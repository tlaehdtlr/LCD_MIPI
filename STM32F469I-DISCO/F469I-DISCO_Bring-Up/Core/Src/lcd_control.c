#include "lcd_control.h"
#include "nt35510.h"
#include "stm32f4xx_hal.h"


static void color_write(uint8_t sector, uint32_t address, uint32_t color)
{
    printf("sector %d, address 0x%08lx, color 0x%08lx \r\n", sector, address, color);
    HAL_StatusTypeDef status;
    uint32_t error = 0;
    FLASH_EraseInitTypeDef eraseInitStruct;

    HAL_FLASH_Unlock();

    eraseInitStruct.TypeErase = FLASH_TYPEERASE_SECTORS;
    eraseInitStruct.VoltageRange = FLASH_VOLTAGE_RANGE_3;
    eraseInitStruct.Sector = sector;
    eraseInitStruct.NbSectors = 1;

    status = HAL_FLASHEx_Erase(&eraseInitStruct, &error);
    if (status != HAL_OK)
    {
        printf("[Error] Flash Erase \r\n");
        HAL_FLASH_Lock();
        return;
    }

    for (uint32_t addr = address; addr < address + 128 * 1024; addr += 4)
    {
        status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, addr, color);
        if (status != HAL_OK)
        {
            printf("[Error] Flash write \r\n");
            break;
        }
    }

    HAL_FLASH_Lock();
}

void lcd_control_change(LCD_CONTROL_COLOR color, bool tmp)
{
    uint32_t color_value = 0xFF000000;
    color_value |= 0xFF<<(color*8);
    if (tmp) // sector 5~11 (128K*7)
    {
        uint32_t address_offset = 0x08020000;
        uint32_t address = 0;
        for (int sector=0; sector<7; sector+=1)
        // for (int sector=0; sector<1; sector+=1)
        {
            address = address_offset + sector*(0x400*128);
            color_write(sector+5, address, color_value);
        }
    }
    else // sector 17~23 (128K*7)
    {
        uint32_t address_offset = 0x08120000;
        uint32_t address = 0;
        for (int sector=0; sector<7; sector+=1)
        {
            address = address_offset + sector*(0x400*128);
            color_write(sector+17, address, color_value);
        }
    }
}

void NT35510_IO_Delay(uint32_t Delay)
{
    HAL_Delay(Delay);
}

static void lcd_reset(void)
{
  HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_RESET);
  HAL_Delay(20);
  HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_SET);
  HAL_Delay(20);
}

void lcd_control_init(void)
{
    lcd_reset();
    MX_DSIHOST_DSI_Init();
    MX_LTDC_Init();
    dsi_start(true);

    NT35510_Init(NT35510_FORMAT_RGB888, LCD_ORIENTATION_LANDSCAPE);

    ltdc_default_init(0, LAYER0_ADDRESS);
}
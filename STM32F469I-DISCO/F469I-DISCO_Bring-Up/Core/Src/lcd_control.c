#include "lcd_control.h"
#include "nt35510.h"
#include "stm32f4xx_hal.h"
#include "vieworks_logo.h"
#include "fmc.h"

#define DMA2D_USE
#define LCD_RECTANGLE_NUM   4

typedef enum
{
    COLOR_STEP_BLACK = 0,
    COLOR_STEP_BLUE,
    COLOR_STEP_GREEN,
    COLOR_STEP_RED,
    COLOR_STEP_CYAN,
    COLOR_STEP_MAGENTA,
    COLOR_STEP_YELLOW,
    COLOR_STEP_WHITE,
    COLOR_STEP_MAX
} COLOR_STEP;

static COLOR_STEP color_rectangles[LCD_RECTANGLE_NUM] = {COLOR_STEP_CYAN, COLOR_STEP_MAGENTA, COLOR_STEP_YELLOW, COLOR_STEP_BLACK};
static const uint32_t colors[COLOR_STEP_MAX] = 
{
    LCD_COLOR_BLACK  ,
    LCD_COLOR_BLUE   ,
    LCD_COLOR_GREEN  ,
    LCD_COLOR_RED    ,
    LCD_COLOR_CYAN   ,
    LCD_COLOR_MAGENTA,
    LCD_COLOR_YELLOW ,
    LCD_COLOR_WHITE  ,
};
static const uint32_t * my_image = vieworks_logo;

void lcd_change_rect_color(uint16_t touch_x, uint16_t touch_y)
{
    uint8_t rect = 0xff;
    if (touch_x < 400)
    {
        if (touch_y < 240)
        {
            rect = 0;
        }
        else
        {
            rect = 2;
        }
    }
    else
    {
        if (touch_y < 240)
        {
            rect = 1;
        }
        else
        {
            rect = 3;
        }
    }

    if (rect != 0xff)
    {
        uint32_t color = LCD_COLOR_BLACK;
        if (++color_rectangles[rect] == COLOR_STEP_MAX)
        {
            color_rectangles[rect] = COLOR_STEP_BLACK;
        }
        else
        {
            color = colors[color_rectangles[rect]];
        }
        lcd_control_change_sdram(color, rect);
    }
}

void lcd_control_draw_rectangle_value(uint32_t layer_index, void* p_dst, uint32_t x_size, uint32_t y_size, uint32_t off_line, uint32_t value)
{
  hdma2d.Init.Mode = DMA2D_R2M;
  hdma2d.Init.ColorMode    = DMA2D_OUTPUT_ARGB8888;
  hdma2d.Init.OutputOffset = off_line;
  if (HAL_DMA2D_Init(&hdma2d) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_DMA2D_ConfigLayer(&hdma2d, 1) != HAL_OK)
  {
    Error_Handler();
  }

  if (HAL_DMA2D_Start(&hdma2d, value, (uint32_t)p_dst, x_size, y_size) == HAL_OK)
  {
      /* Polling For DMA transfer */  
      HAL_DMA2D_PollForTransfer(&hdma2d, 100);
  }
}

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

void lcd_control_change_sdram(uint32_t color, uint8_t sector)
{
    uint32_t address_offset = SDRAM_ADDRESS; // hltdc.LayerCfg[layer_index].FBStartAdress;
    address_offset += (uint32_t)((800*(480/2)*(sector/2)+(800/2)*(sector%2))*4);

#if !defined(DMA2D_USE)
    uint32_t address = 0;
    for (uint16_t y=0; y<240*4; y+=4)
    {
        for (uint16_t x=0; x<400*4; x+=4)
        {
            address = address_offset + 800*y + x;
            *(uint32_t *)address = color;
        }
    }
#else
    lcd_control_draw_rectangle_value(0, (uint32_t *)address_offset, 400, 240, 800 - 400, color);
#endif
}


void lcd_control_change_flash(uint32_t color, bool tmp)
{
    if (!tmp) // sector 5~11 (128K*7)
    {
        uint32_t address_offset = 0x08020000;
        uint32_t address = 0;
        for (int sector=5; sector<7; sector+=1)
        {
            address = address_offset + sector*(0x400*128);
            color_write(sector+5, address, color);
        }
    }
    else // sector 17~23 (128K*7)
    {
        uint32_t address_offset = 0x08120000;
        uint32_t address = 0;
        for (int sector=0; sector<7; sector+=1)
        {
            address = address_offset + sector*(0x400*128);
            color_write(sector+17, address, color);
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

    MX_FMC_Init();

    // ltdc_change_layer(0, *(uint32_t *)my_image);
    ltdc_change_layer(0, *(uint32_t *)my_image);
    lcd_control_change_sdram(LCD_COLOR_CYAN, 0);
    lcd_control_change_sdram(LCD_COLOR_MAGENTA, 1);
    lcd_control_change_sdram(LCD_COLOR_YELLOW, 2);
    lcd_control_change_sdram(LCD_COLOR_BLACK, 3);
    ltdc_change_layer(0, SDRAM_ADDRESS);
}
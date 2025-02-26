#ifndef __LCD_CONTROL_H__
#define __LCD_CONTROL_H__

#include "main.h"
#include "ltdc.h"
#include "dsihost.h"
#include "dma2d.h"

#define LAYER0_ADDRESS              ((uint32_t)0x08020000)
#define SDRAM_ADDRESS               ((uint32_t)0xC0000000)

/**
 * LCD Color
 */
#define LCD_COLOR_BLACK         ((uint32_t) 0xFF000000)
#define LCD_COLOR_BLUE          ((uint32_t) 0xFF0000FF)
#define LCD_COLOR_GREEN         ((uint32_t) 0xFF00FF00)
#define LCD_COLOR_RED           ((uint32_t) 0xFFFF0000)
#define LCD_COLOR_CYAN          ((uint32_t) 0xFF00FFFF)
#define LCD_COLOR_MAGENTA       ((uint32_t) 0xFFFF00FF)
#define LCD_COLOR_YELLOW        ((uint32_t) 0xFFFFFF00)
#define LCD_COLOR_WHITE         ((uint32_t) 0xFFFFFFFF)


typedef enum
{
  LCD_ORIENTATION_PORTRAIT  = 0x00, /*!< Portrait orientation choice of LCD screen  */
  LCD_ORIENTATION_LANDSCAPE = 0x01, /*!< Landscape orientation choice of LCD screen */
  LCD_ORIENTATION_INVALID   = 0x02  /*!< Invalid orientation choice of LCD screen   */
} LCD_OrientationTypeDef;


/** Flash Sector
 * Bank 1 (0x08000000 - 0x080FFFFF):
    Sector 0: 0x08000000 - 0x08003FFF (16 KB)
    Sector 1: 0x08004000 - 0x08007FFF (16 KB)
    Sector 2: 0x08008000 - 0x0800BFFF (16 KB)
    Sector 3: 0x0800C000 - 0x0800FFFF (16 KB)
    Sector 4: 0x08010000 - 0x0801FFFF (64 KB)
    Sector 5: 0x08020000 - 0x0803FFFF (128 KB)
    Sector 6: 0x08040000 - 0x0805FFFF (128 KB)
    Sector 7: 0x08060000 - 0x0807FFFF (128 KB)
    Sector 8: 0x08080000 - 0x0809FFFF (128 KB)
    Sector 9: 0x080A0000 - 0x080BFFFF (128 KB)
    Sector 10: 0x080C0000 - 0x080DFFFF (128 KB)
    Sector 11: 0x080E0000 - 0x080FFFFF (128 KB)
 * Bank 2 (0x08100000 - 0x081FFFFF):
    Sector 12: 0x08100000 - 0x08103FFF (16 KB)
    Sector 13: 0x08104000 - 0x08107FFF (16 KB)
    Sector 14: 0x08108000 - 0x0810BFFF (16 KB)
    Sector 15: 0x0810C000 - 0x0810FFFF (16 KB)
    Sector 16: 0x08110000 - 0x0811FFFF (64 KB)
    Sector 17: 0x08120000 - 0x0813FFFF (128 KB)
    Sector 18: 0x08140000 - 0x0815FFFF (128 KB)
    Sector 19: 0x08160000 - 0x0817FFFF (128 KB)
    Sector 20: 0x08180000 - 0x0819FFFF (128 KB)
    Sector 21: 0x081A0000 - 0x081BFFFF (128 KB)
    Sector 22: 0x081C0000 - 0x081DFFFF (128 KB)
    Sector 23: 0x081E0000 - 0x081FFFFF (128 KB)
 */

void lcd_control_init(void);
void lcd_control_change_sdram(uint32_t color, uint8_t sector);
void lcd_control_change_flash(uint32_t color, bool tmp);
void lcd_control_draw_rectangle_value(uint32_t layer_index, void *p_dst, uint32_t x_size, uint32_t y_size, uint32_t off_line, uint32_t value);
void lcd_change_rect_color(uint16_t touch_x, uint16_t touch_y);
#endif /* __LCD_CONTROL_H__ */
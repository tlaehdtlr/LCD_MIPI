#ifndef __LCD_CONTROL_H__
#define __LCD_CONTROL_H__

#include "main.h"
#include "ltdc.h"
#include "dsihost.h"

typedef enum
{
    eLCD_CONTROL_COLOR_R = 0x02,
    eLCD_CONTROL_COLOR_G = 0x01,
    eLCD_CONTROL_COLOR_B = 0x00,
} LCD_CONTROL_COLOR;

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
void lcd_control_change(LCD_CONTROL_COLOR color, bool tmp);
#endif /* __LCD_CONTROL_H__ */
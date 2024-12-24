#include "sim_lcd.h"


#define LAYER0_ADDRESS  (LCD_FB_START_ADDRESS)
#define LTDC_ACTIVE_LAYER_BACKGROUND      ((uint32_t) 0)

static uint32_t  ActiveLayer = LTDC_ACTIVE_LAYER_BACKGROUND;


void BSP_LCD_SelectLayer(uint32_t LayerIndex)
{
  ActiveLayer = LayerIndex;
}

void BSP_LCD_DisplayOn(void)
{
  /* Send Display on DCS command to display */
  HAL_DSI_ShortWrite(&(hdsi_eval),
                     hdsivideo_handle.VirtualChannelID,
                     DSI_DCS_SHORT_PKT_WRITE_P1,
                     OTM8009A_CMD_DISPON,
                     0x00);
  
}

void BSP_LCD_DisplayOff(void)
{
  /* Send Display off DCS Command to display */
  HAL_DSI_ShortWrite(&(hdsi_eval),
                     hdsivideo_handle.VirtualChannelID,
                     DSI_DCS_SHORT_PKT_WRITE_P1,
                     OTM8009A_CMD_DISPOFF,
                     0x00);
  
}
#ifndef __TOUCH_SCREEN_H__
#define __TOUCH_SCREEN_H__

#include "main.h"
#include "i2c.h"
#include "ft6x06.h"

#define TS_MAX_NB_TOUCH                 ((uint32_t) FT6206_MAX_DETECTABLE_TOUCH)

#define TS_I2C_ADDRESS                   ((uint16_t)0x54)
#define TS_I2C_ADDRESS_A02               ((uint16_t)0x70)
#define TS_SWAP_NONE                    ((uint8_t) 0x01)
#define TS_SWAP_X                       ((uint8_t) 0x02)
#define TS_SWAP_Y                       ((uint8_t) 0x04)
#define TS_SWAP_XY                      ((uint8_t) 0x08)

typedef enum
{
  TS_OK                = 0x00, /*!< Touch Ok */
  TS_ERROR             = 0x01, /*!< Touch Error */
  TS_TIMEOUT           = 0x02, /*!< Touch Timeout */
  TS_DEVICE_NOT_FOUND  = 0x03  /*!< Touchscreen device not found */
} TS_StatusTypeDef;

typedef struct
{
  uint8_t  touchDetected;                /*!< Total number of active touches detected at last scan */
  uint16_t touchX[TS_MAX_NB_TOUCH];      /*!< Touch X[0], X[1] coordinates on 12 bits */
  uint16_t touchY[TS_MAX_NB_TOUCH];      /*!< Touch Y[0], Y[1] coordinates on 12 bits */
} TS_StateTypeDef;

void ts_process(void);
uint8_t ts_init(uint16_t ts_size_x, uint16_t ts_size_y);
uint8_t ts_get_state(TS_StateTypeDef *ts_state);
void ts_write_multi(uint8_t Addr, uint8_t Reg, uint8_t *Buffer, uint16_t Length);

#endif /* __TOUCH_SCREEN_H__ */
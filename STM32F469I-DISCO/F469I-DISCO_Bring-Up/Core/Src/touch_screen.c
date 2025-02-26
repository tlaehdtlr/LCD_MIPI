#include "touch_screen.h"


static TS_DrvTypeDef *ts_driver;
static uint8_t  ts_orientation;
uint8_t  I2C_Address = 0;

TS_StateTypeDef  ts_state = {0};

void ts_process(void)
{
    TS_StateTypeDef  ts_state_new = {0};
    // uint16_t x1, y1;
    ts_get_state(&ts_state_new);
    if (ts_state_new.touchDetected)
    {
        ts_state.touchDetected = ts_state_new.touchDetected;
        if (ts_state.touchX[0] != ts_state_new.touchX[0] || ts_state.touchY[0] != ts_state_new.touchY[0])
        {
            ts_state.touchX[0] = ts_state_new.touchX[0];
            ts_state.touchY[0] = ts_state_new.touchY[0];
            printf("Touch: [%d, %d] \r\n", ts_state.touchX[0], ts_state.touchY[0]);
            lcd_change_rect_color(ts_state.touchX[0], ts_state.touchY[0]);
        }
    }
}


void ts_write_multi(uint8_t Addr, uint8_t Reg, uint8_t *Buffer, uint16_t Length)
{
    HAL_StatusTypeDef status = HAL_OK;

    status = HAL_I2C_Mem_Write(&hi2c1,
                            Addr,
                            (uint16_t)Reg,
                            I2C_MEMADD_SIZE_8BIT,
                            Buffer,
                            Length,
                            1000);

    /* Check the communication status */
    if(status != HAL_OK)
    {
        /* Re-Initiaize the I2C Bus */
        i2c1_error(Addr);
    }
}

uint8_t ts_init(uint16_t ts_size_x, uint16_t ts_size_y)
{
    uint8_t ts_status = TS_OK;
    uint8_t ts_id1, ts_id2 = 0;
    /* Note : I2C_Address is un-initialized here, but is not used at all in init function */
    /* but the prototype of Init() is like that in template and should be respected       */

    /* Initialize the communication channel to sensor (I2C) if necessary */
    /* that is initialization is done only once after a power up         */
    // ft6x06_ts_drv.Init(I2C_Address);

    ts_id1 = ft6x06_ts_drv.ReadID(TS_I2C_ADDRESS);
    if(ts_id1 != FT6206_ID_VALUE)
    {
        ts_id2 = ft6x06_ts_drv.ReadID(TS_I2C_ADDRESS_A02);
        I2C_Address    = TS_I2C_ADDRESS_A02;    
    }
    else
    {
        I2C_Address    = TS_I2C_ADDRESS;    
    }

    /* Scan FT6xx6 TouchScreen IC controller ID register by I2C Read       */
    /* Verify this is a FT6206 or FT6336G, otherwise this is an error case */
    if((ts_id1 == FT6206_ID_VALUE) || (ts_id2 == FT6206_ID_VALUE) || (ts_id2 == FT6X36_ID2_VALUE))
    {
        /* Found FT6206 : Initialize the TS driver structure */
        ts_driver = &ft6x06_ts_drv;

        /* Get LCD chosen orientation */
        if(ts_size_x < ts_size_y)
        {
            ts_orientation = TS_SWAP_NONE;                
        }
        else
        {
            ts_orientation = TS_SWAP_XY | TS_SWAP_Y;                 
        }

        if(ts_status == TS_OK)
        {
            /* Software reset the TouchScreen */
            ts_driver->Reset(I2C_Address);

            /* Calibrate, Configure and Start the TouchScreen driver */
            ts_driver->Start(I2C_Address);

        } /* of if(ts_status == TS_OK) */
    }
    else
    {
        ts_status = TS_DEVICE_NOT_FOUND;
    }

    return (ts_status);
}

uint8_t ts_get_state(TS_StateTypeDef *ts_state)
{
    static uint32_t _x[TS_MAX_NB_TOUCH] = {0, 0};
    static uint32_t _y[TS_MAX_NB_TOUCH] = {0, 0};
    uint8_t ts_status = TS_OK;
    uint16_t tmp;
    uint16_t Raw_x[TS_MAX_NB_TOUCH];
    uint16_t Raw_y[TS_MAX_NB_TOUCH];
    uint16_t xDiff;
    uint16_t yDiff;
    uint32_t index;

    /* Check and update the number of touches active detected */
    ts_state->touchDetected = ts_driver->DetectTouch(I2C_Address);
    if(ts_state->touchDetected)
    {
    for(index=0; index < ts_state->touchDetected; index++)
    {
        /* Get each touch coordinates */
        ts_driver->GetXY(I2C_Address, &(Raw_x[index]), &(Raw_y[index]));

        if(ts_orientation & TS_SWAP_XY)
        {
        tmp = Raw_x[index];
        Raw_x[index] = Raw_y[index]; 
        Raw_y[index] = tmp;
        }
        
        if(ts_orientation & TS_SWAP_X)
        {
        Raw_x[index] = FT_6206_MAX_WIDTH - 1 - Raw_x[index];
        }

        if(ts_orientation & TS_SWAP_Y)
        {
        Raw_y[index] = FT_6206_MAX_HEIGHT - 1 - Raw_y[index];
        }
            
        xDiff = Raw_x[index] > _x[index]? (Raw_x[index] - _x[index]): (_x[index] - Raw_x[index]);
        yDiff = Raw_y[index] > _y[index]? (Raw_y[index] - _y[index]): (_y[index] - Raw_y[index]);

        if ((xDiff + yDiff) > 5)
        {
        _x[index] = Raw_x[index];
        _y[index] = Raw_y[index];
        }


        ts_state->touchX[index] = _x[index];
        ts_state->touchY[index] = _y[index];

    } /* of for(index=0; index < ts_state->touchDetected; index++) */
    } /* end of if(ts_state->touchDetected != 0) */

    return (ts_status);
}


/*********************************************************************************************
 * ft6x06 override
 */
void TS_IO_Init(void)
{
    // MX_I2C1_Init();
    // HAL_GPIO_WritePin(GPIOB, TS_RST_Pin, GPIO_PIN_SET);
    return;
}

void TS_IO_Write(uint8_t Addr, uint8_t Reg, uint8_t Value)
{
    HAL_StatusTypeDef status = HAL_OK;

    status = HAL_I2C_Mem_Write(&hi2c1,
                            Addr,
                            (uint16_t)Reg,
                            I2C_MEMADD_SIZE_8BIT,
                            &Value,
                            1,
                            100);

    /* Check the communication status */
    if(status != HAL_OK)
    {
        /* Execute user timeout callback */
        i2c1_error(Addr);
    }
}

uint8_t TS_IO_Read(uint8_t Addr, uint8_t Reg)
{
    HAL_StatusTypeDef status = HAL_OK;
    uint8_t Value = 0;
    status = HAL_I2C_Mem_Read(&hi2c1,
                            Addr,
                            Reg,
                            I2C_MEMADD_SIZE_8BIT,
                            &Value,
                            1,
                            1000);

    /* Check the communication status */
    if(status != HAL_OK)
    {
        /* Execute user timeout callback */
        i2c1_error(Addr);
    }
    return Value;
}

uint16_t TS_IO_ReadMultiple(uint8_t Addr, uint8_t Reg, uint8_t *Buffer, uint16_t Length)
{
    HAL_StatusTypeDef status = HAL_OK;

    status = HAL_I2C_Mem_Read(&hi2c1,
                        Addr,
                        (uint16_t)Reg,
                        I2C_MEMADD_SIZE_8BIT,
                        Buffer,
                        Length,
                        1000);

    /* Check the communication status */
    if(status != HAL_OK)
    {
        /* I2C error occured */
        i2c1_error(Addr);
    }
    return status;
}

void TS_IO_Delay(uint32_t delay)
{
    HAL_Delay(delay);
}
/******************************** ft6x06 ********************************/
#include "app.h"

#include "main.h"
#include "stdlib.h"
#include "stm32f7xx_hal.h" 
#include "stm32f7xx_hal_gpio.h"
#include "stm32f7xx_hal_pwr.h"
#include "stm32f7xx_hal_rng.h"

#include "../../Middleware/SystemView/SYSVIEW/SEGGER_SYSVIEW.h"
#include "systick_timer_us_delay.h"


uint32_t getRandomNumberInRange(uint32_t min, uint32_t max);

void app_main(void){

  SEGGER_SYSVIEW_Conf();
  SEGGER_SYSVIEW_Start();
  SEGGER_SYSVIEW_PrintfHost("This is a test message to ensure SysView is working.\n");

  HAL_DBGMCU_EnableDBGSleepMode();

  __enable_irq();
  __ISB();

  uint32_t iteration = 0;
  uint32_t doStuffTime_us;
  timerDone =0;
  while(timerDone==0);
  __disable_irq();

  while (1){
    iteration++;
    timerDone = 0;
    __enable_irq();
    __ISB();

    HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_SET);
    doStuffTime_us = getRandomNumberInRange(200,600);
    delay_us(doStuffTime_us);
    HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_RESET);

    if (timerDone == 1)
    {
        HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
        SEGGER_SYSVIEW_PrintfHost("ERROR: Iteration %d, Sysclock done before function completed!!\n", iteration);
    }

    __disable_irq();
    while (timerDone == 0){
        HAL_PWR_EnterSLEEPMode(0, PWR_SLEEPENTRY_WFI);
        __enable_irq();
        __ISB();
        __disable_irq();
    }



  }
}

uint32_t getRandomNumberInRange(uint32_t min, uint32_t max) {
    uint32_t randomNumber;
    if (min > max) {
        Error_Handler();
    }

    if (HAL_RNG_GenerateRandomNumber(&hrng, &randomNumber) != HAL_OK )
    {
        Error_Handler();
    }

    return ( min + (randomNumber & (max - min) ));
}


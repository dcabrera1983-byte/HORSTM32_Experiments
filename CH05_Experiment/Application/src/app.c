#include "app.h"

#include "main.h"
#include "stdlib.h"
#include "stm32f7xx_hal.h" 

#include "../../Middleware/SystemView/SYSVIEW/SEGGER_SYSVIEW.h"


void app_main(void){


  SEGGER_SYSVIEW_Conf();
  SEGGER_SYSVIEW_Start();
  SEGGER_SYSVIEW_PrintfHost("This is a demo test.\n");

  int iteration = 0;

  while (1){
    SEGGER_SYSVIEW_PrintfHost("This is iteration: %d", iteration++);
    HAL_Delay(1000);
  }
}
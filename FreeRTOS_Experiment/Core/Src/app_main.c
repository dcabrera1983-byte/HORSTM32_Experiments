
#include "main.h"
#include "app_main.h"

#include "../../Middleware/Third-Party/FreeRTOS/Source/include/FreeRTOS.h"
#include "../../Middleware/Third-Party/FreeRTOS/Source/include/task.h"
#include "portmacro.h"
#include "stm32f7xx_hal_gpio.h"
#include "SEGGER_SYSVIEW.h"

void TaskLoop1(void *arguments);
void TaskLoop2(void *arguments);


void APP_main_init(){

    SEGGER_SYSVIEW_Conf();
    
    xTaskCreate(TaskLoop1, "Task 1", 128, NULL, 5, NULL);
    xTaskCreate(TaskLoop2, "Task 2", 128, NULL, 5, NULL);

    vTaskStartScheduler();
}


void TaskLoop1(void *arguments){

    while( SEGGER_SYSVIEW_IsStarted() == 0){
        HAL_Delay(10);
    }
    SEGGER_SYSVIEW_PrintfHost("TASK1: Starting!\n");

    while(1){
        HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

void TaskLoop2(void *arguments){

    while(1){
        HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
        vTaskDelay(500/portTICK_PERIOD_MS);
    }
}
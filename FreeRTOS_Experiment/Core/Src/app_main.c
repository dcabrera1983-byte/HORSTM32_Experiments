
#include "main.h"
#include "app_main.h"

#include "../../Middleware/Third-Party/FreeRTOS/Source/include/FreeRTOS.h"
#include "../../Middleware/Third-Party/FreeRTOS/Source/include/task.h"
#include "stm32f7xx_hal_gpio.h"

void TaskLoop1(void *arguments);
void TaskLoop2(void *arguments);


void APP_main_init(){
    
    xTaskCreate(TaskLoop1, "Task 1", 128, NULL, 1, NULL);

    vTaskStartScheduler();
}


void TaskLoop1(void *arguments){

    while(1){
        HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
        HAL_Delay(1000);
    }
}
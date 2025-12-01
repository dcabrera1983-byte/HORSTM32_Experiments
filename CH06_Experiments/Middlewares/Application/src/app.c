
#include "app.h"
#include "main.h"
#include "cmsis_os.h"

#include "../../Third_Party/SEGGER/SystemView/SYSVIEW/SEGGER_SYSVIEW.h"
#include "portmacro.h"


void Task1(void *arg);
void Task2(void *arg);
void Task3(void *arg);

void APP_Init(void){

    SEGGER_SYSVIEW_Conf();

    const static uint32_t stackSize = 128;

    xTaskCreate(Task1,"Task_1", stackSize, NULL, tskIDLE_PRIORITY + 3, NULL);
    xTaskCreate(Task2,"Task_2", stackSize, NULL, tskIDLE_PRIORITY + 3, NULL);
    xTaskCreate(Task3,"Task_3", stackSize, NULL, tskIDLE_PRIORITY + 3, NULL);
}



void Task1(void *arg){

    SEGGER_SYSVIEW_Start();
    
    SEGGER_SYSVIEW_PrintfHost("TASK1: Starting!\n");

    while(1){
        SEGGER_SYSVIEW_PrintfHost("This is TASK1, every 1s\n");
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

void Task2(void *arg){
    SEGGER_SYSVIEW_PrintfHost("TASK2: Starting!\n");
    while(1){
        SEGGER_SYSVIEW_PrintfHost("This is TASK2, every 3s\n");
        vTaskDelay(3000/portTICK_PERIOD_MS);
    }
}

void Task3(void *arg){
    SEGGER_SYSVIEW_PrintfHost("TASK3: Starting!\n");
    while(1){
        SEGGER_SYSVIEW_PrintfHost("This is TASK3, every 5s\n");
        vTaskDelay(5000/portTICK_PERIOD_MS);
    }
}
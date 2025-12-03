
#include "app.h"
#include "main.h"
#include "cmsis_os.h"
#include "board_controller.h"
#include "lookBusy.h"

#include "../../Third_Party/SEGGER/SystemView/SYSVIEW/SEGGER_SYSVIEW.h"
#include "portmacro.h"


void Task1(void *arg);
void Task2(void *arg);
void Task3(void *arg);

extern uint32_t iterationsPerMs;

void APP_Init(void){

    // iterationsPerMS, needs to be collected outside of this initialize because freertos kernel initialization masks
    // the TIM7 and will cause the function to hang.

    SEGGER_SYSVIEW_Conf();

    const static uint32_t stackSize = 128;

    xTaskCreate(Task1,"Task_1", stackSize, NULL, tskIDLE_PRIORITY + 3, NULL);
    xTaskCreate(Task2,"Task_2", stackSize, NULL, tskIDLE_PRIORITY + 2, NULL);
    xTaskCreate(Task3,"Task_3", stackSize, NULL, tskIDLE_PRIORITY + 1, NULL);

    //Schedule Start is run at the main.c so we dont need to do it from here. All we are doing is setting up the tasks
}



void Task1(void *arg){

    uint32_t lookBusyIterations;
    uint32_t iterations = 0;

    BlueLED.On();
    while( SEGGER_SYSVIEW_IsStarted() == 0){
        HAL_Delay(10);
    }
    BlueLED.Off();

    SEGGER_SYSVIEW_PrintfHost("TASK1: Starting!\n");

    lookBusyIterations = iterationsPerMs /4;

    while(1){
        if ((iterations % 100) == 1)
        { 
            SEGGER_SYSVIEW_PrintfHost("TASK1: Iteration %u\n", iterations);
        }
        lookBusy(lookBusyIterations);

        vTaskDelay(5);
        iterations++;
    }
}

void Task2(void *arg){

    uint32_t lookBusyIterations;
    uint32_t iterations = 0;

    SEGGER_SYSVIEW_PrintfHost("TASK2: Starting!\n");
    lookBusyIterations = iterationsPerMs / 2;
    while(1){
        if ((iterations % 100) == 1)
        { 
            SEGGER_SYSVIEW_PrintfHost("TASK2: Iteration %u\n", iterations);
        }
        lookBusy(lookBusyIterations);
        vTaskDelay(1);
        iterations++;
    }
}

void Task3(void *arg){

    uint32_t lookBusyIterations;
    uint32_t iterations = 0;

    SEGGER_SYSVIEW_PrintfHost("TASK3: Starting!\n");

    lookBusyIterations = iterationsPerMs * 2;

    while(1){
        if ((iterations % 100) == 1)
        { 
            SEGGER_SYSVIEW_PrintfHost("TASK3: Iteration %u\n", iterations);
        }
        lookBusy(lookBusyIterations);
        iterations++;
    }
}
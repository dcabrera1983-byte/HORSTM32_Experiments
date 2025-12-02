#ifndef __BOARD_CONTROLLER_H
#define __BOARD_CONTROLLER_H

#include "main.h"

#define GREEN_LED   LD1_Pin
#define GREEN_PORT  LD1_GPIO_Port
#define BLUE_LED    LD2_Pin
#define BLUE_PORT   LD2_GPIO_Port
#define RED_LED     LD3_Pin
#define RED_PORT    LD3_GPIO_Port
#define BTN_PIN     USER_Btn_Pin
#define BTN_PORT    USER_Btn_GPIO_Port

typedef void (*GPIOFunc) (void); 

typedef struct {
    const GPIOFunc On;
    const GPIOFunc Off;
} LED;

uint8_t ReadPushButton(void);

extern LED GreenLED;
extern LED BlueLED;
extern LED RedLED;

#endif
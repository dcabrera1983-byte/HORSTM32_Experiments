
#include "board_controller.h"


void GreenOn(void) {HAL_GPIO_WritePin(GREEN_PORT,GREEN_LED,  GPIO_PIN_SET);}
void GreenOff(void) {HAL_GPIO_WritePin(GREEN_PORT,GREEN_LED,  GPIO_PIN_RESET);}
LED GreenLED = { GreenOn, GreenOff };

void BlueOn(void) {HAL_GPIO_WritePin(BLUE_PORT,BLUE_LED,  GPIO_PIN_SET);}
void BlueOff(void) {HAL_GPIO_WritePin(BLUE_PORT,BLUE_LED,  GPIO_PIN_RESET);}
LED BlueLED = { BlueOn, BlueOff };

void RedOn(void) {HAL_GPIO_WritePin(RED_PORT,RED_LED,  GPIO_PIN_SET);}
void RedOff(void) {HAL_GPIO_WritePin(RED_PORT,RED_LED,  GPIO_PIN_RESET);}
LED RedLED = { RedOn, RedOff };

uint8_t ReadPushButton() { return HAL_GPIO_ReadPin(BTN_PORT, BTN_PIN);}
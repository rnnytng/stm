#include "stm32f10x.h"
void light_init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef aa;
	aa.GPIO_Mode=GPIO_Mode_IPU;
	aa.GPIO_Pin=GPIO_Pin_11;
	aa.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&aa);
}
uint8_t light_get(){
	return GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11);
}
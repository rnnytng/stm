#include "stm32f10x.h"
void butter_init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef aa;
	aa.GPIO_Mode=GPIO_Mode_Out_PP;
	aa.GPIO_Pin=GPIO_Pin_13;
	aa.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&aa);
}
void butter_on(){
	GPIO_ResetBits(GPIOB,GPIO_Pin_13);
}
void butter_turn(){
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13)==0){
		GPIO_SetBits(GPIOB,GPIO_Pin_13);
		
	}
	else{
		GPIO_ResetBits(GPIOB,GPIO_Pin_13);
	}
}
void butter_off(){
	GPIO_SetBits(GPIOB,GPIO_Pin_13);
}
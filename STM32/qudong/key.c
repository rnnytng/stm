#include "stm32f10x.h"
#include "Delay.h"
void key_init(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef bb;
	bb.GPIO_Mode=GPIO_Mode_IPU;
	bb.GPIO_Pin=GPIO_Pin_12 | GPIO_Pin_6;
	bb.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&bb);
	
}
uint8_t key_num(){
	uint8_t keynum=0;
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)==0){
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)==0);
		Delay_ms(20);
		keynum=1;
		 
	}
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6)==0){
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6)==0);
		Delay_ms(20);
		keynum=2;
		 
	}
	return keynum;
}
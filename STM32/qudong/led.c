#include "stm32f10x.h"
#include "Delay.h"
void led_init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef aa;
	aa.GPIO_Mode=GPIO_Mode_Out_PP;
	aa.GPIO_Pin=GPIO_Pin_All;
	aa.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&aa);
}
void led_on(){

	
		 GPIO_Write(GPIOA,~0x0001);
		Delay_ms(100);
		GPIO_Write(GPIOA,~0x0002);
		Delay_ms(100);
		GPIO_Write(GPIOA,~0x0004);
		Delay_ms(100);
		GPIO_Write(GPIOA,~0x0020);
		Delay_ms(100);
	
	
	
	 
}
void led_turn(){
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==0){
		GPIO_SetBits(GPIOA,GPIO_Pin_0);
		
	}
	else{
		GPIO_ResetBits(GPIOA,GPIO_Pin_0);
	}
}
void led_off(){
	GPIO_SetBits(GPIOA,GPIO_Pin_All);
}
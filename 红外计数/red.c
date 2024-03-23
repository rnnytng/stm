#include "stm32f10x.h"  
// Device header
uint16_t count;
void red_init(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef aa;
	aa.GPIO_Mode=GPIO_Mode_IPU;
	aa.GPIO_Pin=GPIO_Pin_11;
	aa.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&aa);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource11);
	
	EXTI_InitTypeDef ex;
	ex.EXTI_Line=EXTI_Line11;
	ex.EXTI_LineCmd=ENABLE;
	ex.EXTI_Mode=EXTI_Mode_Interrupt;
	ex.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&ex);
	
	NVIC_PriorityGroupConfig( NVIC_PriorityGroup_2);
	NVIC_InitTypeDef nv;
	nv.NVIC_IRQChannel=EXTI15_10_IRQn;
	nv.NVIC_IRQChannelCmd=ENABLE;
	nv.NVIC_IRQChannelPreemptionPriority=1;
	nv.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&nv);
	
}
uint16_t getnum(){
	return count;
}
void EXTI15_10_IRQHandler()
{
	if(EXTI_GetFlagStatus(EXTI_Line11)==SET){
		count ++;
		EXTI_ClearITPendingBit(EXTI_Line11);
	}
}

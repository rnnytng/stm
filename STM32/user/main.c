// ������--B13
// ����--B11
//�����ֱܷ�--0 1 2 5
//����--B6 B12
//�����п��������������ؿ��ƵƵ�������Ҳ��������һ�����ؿ��ơ�

#include "stm32f10x.h"
#include "Delay.h"
#include "led.h"
#include "key.h"
#include "butter.h"
#include "light.h"
uint8_t keynum;
int main(){
	
	led_init();
	key_init();
	butter_init();
	light_init();
	while(1){
		keynum=key_num();
		if(keynum==0 && light_get()==0){
			
				led_on();
				butter_on();
			  
			
		}
		if(light_get()==1){
			butter_off();
			led_off();
		}
		 if(keynum==2 ){
			butter_off();
			led_off();
			break;
		}

	}
}
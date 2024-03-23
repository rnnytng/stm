#include "stm32f10x.h"
#include "OLED.h"
#include "Delay.h"
#include "red.h"
int main(){
		OLED_Init();
		red_init();
		OLED_ShowString(1,1,"num:");
	while(1){
		OLED_ShowNum(1,5,getnum(),5);
		
	}
	
}
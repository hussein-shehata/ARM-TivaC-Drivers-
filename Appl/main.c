#include "IntCtrl.h"
#include "GPT.h"
#include "PORT.h"
#include "DIO.h"
#include "Platform_Types.h"
#include "LED.h"

void Gpt_Notfication_TIMER1(void)
{
	static uint8 Flag = 0;

	if (Flag == 1)
	{
		LED_OFF();
		
	}

	else if (Flag == 3)
	{
		LED_ON();
		Flag = 0;
	}
	
	Flag++;
}


int main(void)
{
	
	IntCrtl_Init();
	Port_Init(Port_Configurations);
	Gpt_Init(Configurations_Timer);
	
	Gpt_EnableNotification(GPT_TIMER1);
	Gpt_StartTimer(GPT_TIMER1, 64000 - 1);

	while(1)
	{
		
	}
	
}

#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main(void)
{
//  使用RCC开启GPIO的时钟
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
//  使用GPIO_Init函数初始化GPIO
	//	该代码是定义结构体的形参，名字为GPIO_Instructure
		GPIO_InitTypeDef GPIO_Instructure;
	//	推挽输出模式
		GPIO_Instructure.GPIO_Mode = GPIO_Mode_Out_PP;
	//	引脚0
		GPIO_Instructure.GPIO_Pin = GPIO_Pin_0;
	//	输出速度为50MHz	
		GPIO_Instructure.GPIO_Speed = GPIO_Speed_50MHz;
	//	GPIO的0号引脚就被设置为了推挽输出模式，50MHz的速度了
		GPIO_Init(GPIOA, &GPIO_Instructure);
		
	while(1)
	{	
//	使用输出或输入函数控制GPIO口
		GPIO_SetBits(GPIOA,GPIO_Pin_0);
		Delay_ms(500);
		GPIO_ResetBits(GPIOA,GPIO_Pin_0);
		Delay_ms(500);
		GPIO_WriteBit(GPIOA,GPIO_Pin_0,(BitAction)0);
		Delay_ms(500);
		GPIO_WriteBit(GPIOA,GPIO_Pin_0,(BitAction)1);
		Delay_ms(500);
	}
}
 
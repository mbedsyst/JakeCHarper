#include "Keyboard.h"
#include "Delay.h"
#include "GPIO.h"
#include "stm32f4xx.h"

void playNote(uint16_t period, uint16_t duration)
{
 uint16_t elapsed;
 uint16_t i;
 for (elapsed = 0; elapsed < duration; elapsed += period)
 {
  /* For loop with variable delay selects the pitch */
  for (i = 0; i < period; i++)
  {
   delay_us(1);
  }
  GPIO_Toggle();
 }
}

void rest(uint16_t duration)
{
	do
	{
	 delay_us(1);
	}
	while (--duration);
}

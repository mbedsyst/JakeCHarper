/* Author      : mbedsyst/Zalman Ul Fariz P A
 * Title       : MusicalKeyboard
 * Description : Application code for a Musical Keyboard on STM32F401 using UART and
 *               GPIO Peripherals.
 */

#include "stm32f4xx.h"
#include "Keyboard.h"
#include "Delay.h"
#include "UART.h"
#include "GPIO.h"

#define NOTE_DURATION   0xF000


int main(void)
{

	char rx_char;
	uint16_t currentNoteLength = NOTE_DURATION / 2;
	const uint8_t keys[] = { 'a', 'w', 's', 'e', 'd', 'f', 't',
							 'g', 'y', 'h', 'j', 'i', 'k', 'o',
							 'l', 'p', ';', '\''
	                       };
	const uint16_t notes[] = { G4, Gx4, A4, Ax4, B4, C5, Cx5,
							   D5, Dx5, E5, F5, Fx5, G5, Gx5,
							   A5, Ax5, B5, C6
							 };
	uint8_t isNote;
	uint8_t i;

	UART_Init();
	GPIO_Init();
	UART_Tx_String("\n____MUSICAL KEYBOARD____\r\n");

	while (1)
    {
		/* Get Key */
		rx_char = UART_Rx();          			/* waits here until there is input */
	    UART_Tx_String("\r\n");
		UART_Tx('N');                 			/* alert computer we're ready for next note */

		/* Play Notes */
		isNote = 0;
		for (i = 0; i < sizeof(keys); i++)
		{
			if (rx_char == keys[i])
			{
				/* Found match in lookup table */
				playNote(notes[i], currentNoteLength);
				isNote = 1;                          /* record that we've found a note */
				break;                               /* drop out of for() loop */
			}
		}
		/* Handle non-note keys: Tempo changes and rests */
		if (!isNote)
		{
			if (rx_char == '[')
			{
				/* Code for short note */
				currentNoteLength = NOTE_DURATION / 2;
     		}
			else if (rx_char == ']')
			{
				/* Code for long note */
				currentNoteLength = NOTE_DURATION;
			}
			else
			{
				/* Unrecognized, just rest */
				rest(currentNoteLength);
			}
		}

    }/* End event loop */
    return 0;
}

#include "my_led_seq.h"

void delay_ms(void)
{
    for (volatile int i = 0; i < 100; i++); // debounce delay
}

int main(void)
{
    uint8_t last_state = 0;
    uint8_t current_state = 0;
    uint8_t press_count = 0;

    GPIO_Init();
    All_LED_Off();

    while (1)
    {
        current_state = Read_Switch();

        /* Detect button press (0 → 1) */
        if (current_state == 1 && last_state == 0)
        {
            delay_ms();   // debounce

            if (Read_Switch() == 1)
            {
                press_count++;

                if (press_count == 1)
                {
                    Green_LED_On();   // 1st press
                }
                else if (press_count == 2)
                {
                    Blue_LED_On();    // 2nd press
                }
                else if (press_count == 3)
                {
                    All_LED_Off();    // 3rd press
                    press_count = 0;  // reset cycle
                }
            }
        }

        last_state = current_state;
    }
}

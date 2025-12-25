#include "my_led.h"

void delay_ms(void)
{
    for (volatile int i = 0; i < 300000; i++); // simple delay
}

int main(void)
{
    uint8_t last_state = 0;
    uint8_t current_state = 0;

    GPIO_Init();

    while (1)
    {
        current_state = Read_Switch();

        /* Detect rising edge (button press) */
        if (current_state == 1 && last_state == 0)
        {
            delay_ms();              // debounce delay

            if (Read_Switch() == 1)  // confirm press
            {
                LED_Toggle();        // toggle LED
            }
        }

        last_state = current_state;
    }
}

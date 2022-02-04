#include "pico/stdlib.h"
#define true 1
/**
 * @brief LAB #01 - TEMPLATE
 *        Main entry point for the code.
 * 
 * @return int      Returns exit-status zero on completion.
 */
void loop(int pin_number, int sleep_delay) {
while (true) {

        // Toggle the LED on and then sleep for delay period
        gpio_put(pin_number, 1);
        sleep_ms(sleep_delay);

        // Toggle the LED off and then sleep for delay period
        gpio_put(pin_number, 0);
        sleep_ms(sleep_delay);

    }
}

int main() {

    // Specify the PIN number and sleep delay
    const unsigned int LED_PIN   =  25;
    const unsigned int LED_DELAY = 500;

    // Setup the LED pin as an output.
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Do forever...
    loop(LED_PIN, LED_DELAY);

    // Should never get here due to infinite while-loop.
    return 0;

}
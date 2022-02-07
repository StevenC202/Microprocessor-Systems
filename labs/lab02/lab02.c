#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pico/stdlib.h"
#include "pico/float.h"     // Required for using single-precision variables.
#include "pico/double.h"    // Required for using double-precision variables.


/**
 * @brief LAB #02 - TEMPLATE
 *        Main entry point for the code.
 * 
 * @return int      Returns exit-status zero on completion.
 */

void float_wallis() {
    float pi;
    for(int i = 1; i < 100001; i++) {
        pi = pi * ( (2*i/2*i-1) * (2*i/2*i+1) );
    }
    int approximation_error = ((pi - 3.14159265359) / 3.14159265359) * 100;
    printf("The calculated value using floating point is %f\n", pi);
    printf("The approximation error calculated for this value is %d", approximation_error);
}

void double_wallis() {
    double pi;
    for(int i = 1; i < 100001; i++) {
        pi = pi * ( (2*i/2*i-1) * (2*i/2*i+1) );
    }
    int approximation_error = ((pi - 3.14159265359) / 3.14159265359) * 100;
    printf("The calculated value using floating point is %f\n", pi);
    printf("The approximation error calculated for this value is %d", approximation_error);
}



int main() {

#ifndef WOKWI
    // Initialise the IO as we will be using the UART
    // Only required for hardware and not needed for Wokwi
    stdio_init_all();
#endif

    // Print a console message to inform user what's going on.
    printf("Calculating pi using floating point representation:\n");
    float_wallis();

    printf("Calculating pi using double precision\n");
    double_wallis();

    // Returning zero indicates everything went okay.
    return 0;
}

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

/**
    For loop to calculate wallis series needs to continuously multiply
    the value for n -> infinity.
*/

void float_wallis() {
    float pi = 1.0; // starting value for wallis series
    float actual_value = 3.14159265359;
    for(float i = 1.0; i < 100000; i++) {
        pi = pi * ( ((2.0*i)/(2.0*i-1.0) )* ( (2.0*i)/(2.0*i+1.0)) ); // wallis series calculated using a for loop 100,000 times
    }
    pi = pi * 2; // double value calculated
    float approximation_error = abs( ((pi - actual_value)/actual_value)*100.0); 
    printf("The calculated value using floating point is %f\n", pi);
    printf("The percentage error calculated for this value is %f%% \n ", approximation_error);
}
 
void double_wallis() {
    double pi = 1.00;
    double actual_value = 3.14159265359;
    for(double i = 1.00; i < 100000; i++) {
        pi = pi * ( ((2.00*i)/(2.00*i-1.00) )* ( (2.00*i)/(2.00*i+1.00)) ); // same for loop, except using double representation
    }
    pi = pi*2.0;
    double approximation_error = abs(((pi - actual_value) / actual_value) * 100.00);
    printf("The calculated value using double precision is %f\n", pi);
    printf("The percentage error calculated for this value is %f%%\n", approximation_error);
}



int main() {

#ifndef WOKWI
    // Initialise the IO as we will be using the UART
    // Only required for hardware and not needed for Wokwi
    //stdio_init_all();
#endif

    // Print a console message to inform user what's going on.
    printf("Calculating pi using floating point representation:\n");
    float_wallis();

    printf("Calculating pi using double precision:\n");
    double_wallis();

    // Returning zero indicates everything went okay.
    return 0;
}
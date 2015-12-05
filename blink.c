#include <bcm2835.h>
#include <stdio.h>
#include <string.h>

#define BLU RPI_GPIO_P1_12
#define RED RPI_GPIO_P1_11

int main(int argc, char **argv) {
    
    // Initializes bcm2835 library.
    // Sets up options and configures registers of BCM2835.
    if(!bcm2835_init())return 1;

    // Set pin direction
    bcm2835_gpio_fsel(BLU, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(RED, BCM2835_GPIO_FSEL_OUTP);
    unsigned int delay = 250;

    printf("%s\n", argv[1]);

    // if we pass in "off" as the command line argument
    // we turn off the LEDs and exit
    if(strcmp(argv[1],"off") == 0) {
        bcm2835_gpio_clr(BLU);
        bcm2835_gpio_clr(RED);
        return 1;
    } else {
        while(1) {
            bcm2835_gpio_set(BLU);
            bcm2835_delay(delay);
            bcm2835_gpio_clr(BLU);
            bcm2835_delay(delay);
            bcm2835_gpio_set(BLU);
            bcm2835_delay(delay);
            bcm2835_gpio_clr(BLU);
    //        bcm2835_delay(delay);
            bcm2835_gpio_set(RED);
            bcm2835_delay(delay);
            bcm2835_gpio_clr(RED);
            bcm2835_delay(delay);
            bcm2835_gpio_set(RED);
            bcm2835_delay(delay);
            bcm2835_gpio_clr(RED);
    //        bcm2835_delay(delay);
            bcm2835_gpio_set(BLU);
            bcm2835_delay(delay);
            bcm2835_gpio_clr(BLU);
    //        bcm2835_delay(delay);
            bcm2835_gpio_set(RED);
            bcm2835_delay(delay);
            bcm2835_gpio_clr(RED);
    //        bcm2835_delay(delay);
            bcm2835_gpio_set(BLU);
            bcm2835_delay(delay);
            bcm2835_gpio_clr(BLU);
    //        bcm2835_delay(delay);
            bcm2835_gpio_set(RED);
            bcm2835_delay(delay);
            bcm2835_gpio_clr(RED);
    //        bcm2835_delay(delay);
        }
    }
}

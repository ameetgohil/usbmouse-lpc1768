// USB Device demo - control mouse pointer with buttons

#include "mbed.h"
#include "USBMouse.h"

// USB Mouse object
USBMouse mouse;

// Define buttonns
DigitalIn button_up(p5);
DigitalIn button_down(p6);
DigitalIn button_left(p7);
DigitalIn button_right(p8);

DigitalOut myled(LED1);

int main() {
    int x = 0;
    int y = 0;
    
    while (1) {
        
        //Determine mouse pointer horizontal direction
        x = button_left ^ button_right;
        if( button_right ) {
            x = -1 *x;
        }
        
        //Determine mouse pointer vertical direction
        y = button_up ^ button_down;
        if ( button_down ) {
            y = -1 * y;
        }
        
        // Move mouse
        mouse.move(x,y);
        
        //Wait for next cycle
        wait(0.001);
    }
}

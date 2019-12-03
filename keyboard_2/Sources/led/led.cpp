#include "led.h"

Led::Led(gpio_Pin pin) {

    led = mkl_GPIOPort(pin);
    led.setPortMode(gpio_output);

}

void Led::turnOn() {
    led.writeBit(0);
}

void Led::turnOff() {
    led.writeBit(1);
}
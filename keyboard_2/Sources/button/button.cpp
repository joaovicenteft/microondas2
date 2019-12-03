#include "button.h"

Button::Button(gpio_Pin pin) {
    button = mkl_GPIOPort(pin);
    button.setPortMode(gpio_input);
}

bool Button::isPressed() {
    int outReadBit = button.readBit();

    if (outReadBit) {
        return true;
    } else {
        return false;
    }
}
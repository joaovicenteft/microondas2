#include "stdint.h"
#include "mkl_GPIO/mkl_GPIOPort.h"

class Button {

    private:
        mkl_GPIOPort button;

    public:
        Button(gpio_Pin pin);

};
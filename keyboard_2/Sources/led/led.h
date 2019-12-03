#include "stdint.h"
#include "mkl_GPIO/mkl_GPIOPort.h"

class Led {

    private:
        mkl_GPIOPort led;

    public:
        Led(gpio_Pin pin);

};
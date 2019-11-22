#ifndef SEVEN_SEGMENTS_H_
#define SEVEN_SEGMENTS_H_

#include "../mkl_GPIO/mkl_GPIOPort.h"
#include "MKL25Z4.h"


class sevenSegments {

	private:
		mkl_GPIOPort a, b, c, d, e, f, g, p, D1, D2, D3, D4;

    public:
        sevenSegments(gpio_Pin pa, gpio_Pin pb, gpio_Pin pc, gpio_Pin pd,
        gpio_Pin pe, gpio_Pin pf, gpio_Pin pg, gpio_Pin pD1, gpio_Pin pD2, gpio_Pin pD3, gpio_Pin pD4);

        void clear();
        void zero();
        void one();
        void two();
        void three();
        void four();
        void five();
        void six();
        void seven();
        void eight();
        void nine();

        void turnOnSevenSegments(int number, int position);

};


#endif

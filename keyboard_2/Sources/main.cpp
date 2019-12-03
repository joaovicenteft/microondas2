#include <stdint.h>
#include <MKL25Z4.h>
#include <mkl_GPIO/mkl_GPIOPort.h>
#include <mkl_KeyboardParallelPort/mkl_KeyboardParallelPort.h>
#include "mkl_SystickPeriodicInterrupt/mkl_SystickPeriodicInterrupt.h"
#include "7segments/sevenSegments.h"

// declarations of keyboard patterns

mkl_KeyboardParallelPort keyboard(gpio_PTC0, gpio_PTE5, gpio_PTE4, gpio_PTC3,
gpio_PTC4, gpio_PTC5, gpio_PTC6, gpio_PTC7);

mkl_SystickPeriodicInterrupt systick = mkl_SystickPeriodicInterrupt(10, clock42Mhz);

sevenSegments sevensegments = sevenSegments(gpio_PTD3, gpio_PTA13, gpio_PTA17, gpio_PTD5, gpio_PTC17, gpio_PTC16, gpio_PTC13,
		gpio_PTE1, gpio_PTD4, gpio_PTA2, gpio_PTD7);

char key;

void setupLED() {

	/* redLed.setPortMode(gpio_output);
	blueLed.setPortMode(gpio_output);
	greenLed.setPortMode(gpio_output);
	redLed.writeBit(1);
	blueLed.writeBit(1);
	greenLed.writeBit(1); */
}

void changeKeyboard() {
	switch(key){
			case 0x0:
				for (int i = 1; i < 5; i++)
					sevensegments.turnOnSevenSegments(0, i);
				break;
			case 0x1:
				for (int i = 1; i < 5; i++)
					sevensegments.turnOnSevenSegments(1, i);
				break;
			case 0x2:
				for (int i = 1; i < 5; i++)
					sevensegments.turnOnSevenSegments(2, i);
				break;
			case 0x3:
				for (int i = 1; i < 5; i++)
					sevensegments.turnOnSevenSegments(3, i);
				break;
			case 0x4:
				for (int i = 1; i < 5; i++)
					sevensegments.turnOnSevenSegments(4, i);
				break;
			case 0x5:
				for (int i = 1; i < 5; i++)
					sevensegments.turnOnSevenSegments(5, i);
				break;
			case 0x6:
				for (int i = 1; i < 5; i++)
					sevensegments.turnOnSevenSegments(6, i);
				break;
			case 0x7:
				for (int i = 1; i < 5; i++)
					sevensegments.turnOnSevenSegments(7, i);
				break;
			case 0x8:
				for (int i = 1; i < 5; i++)
					sevensegments.turnOnSevenSegments(8, i);
				break;
			case 0x9:
				for (int i = 1; i < 5; i++)
					sevensegments.turnOnSevenSegments(9, i);
				break;
	}
}

void delay() {
	int count = 10;

	while (count > 0) {
		count--;
	}
}


void counterSevenSegments(void) {

	int positionOfBCD = 4;

	while (positionOfBCD > 0) {
		int numberOfBCD = 9;
		while (numberOfBCD > 0) {
			delay();
			sevensegments.turnOnSevenSegments(numberOfBCD, positionOfBCD);
			numberOfBCD--;
		}
		positionOfBCD--;
	}
}

extern "C" {
    void SysTick_Handler(void) {
    	keyboard.update();
        key = keyboard.getKey();
        changeKeyboard();
    }
}

int main(){

	while(1){
		//counterSevenSegments();
		SysTick_Handler();
	}
	return 0;
}


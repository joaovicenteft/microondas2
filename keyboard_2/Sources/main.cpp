/*!
 * @copyright   2019 Universidade Federal do Amazonas.
 *
 * @brief       Programa exemplo de uso da classe mkl_KeyboardParallelPort.
 *
 * @file        main.cpp
 * @version     1.0
 * @date        04 Mar�o 2019
 *
 * @section     HARDWARES & SOFTWARES
 *              +board        FRDM-KL25Z da NXP.
 *              +processor    MKL25Z128VLK4 - ARM Cortex-M0+
 *              +compiler     Kinetis Design Studio IDE
 *              +manual       L25P80M48SF0RM, Rev.3, September 2012
 *              +revisions    Versao (data): Descricao breve.
 *                             ++ 1.0 (04 Mar�o 2019): Versao inicial.
 *
 * @section     AUTHORS & DEVELOPERS
 *              +institution  Universidade Federal do Amazonas
 *              +courses      Engenharia da Computacao
 *              +teacher      Miguel Grimm <miguelgrimm@gmail.com>
 *              +student      Versao inicial:
 *                             ++ Daniel Modesto de Souza <daniel.modesto.dmds@gmail.com>
 *
 *
 * @section     LICENSE
 *
 *              GNU General Public License (GNU GPL).
 *
 *              Este programa e um software livre; Voce pode redistribui-lo
 *              e/ou modifico-lo de acordo com os termos do "GNU General Public
 *              License" como publicado pela Free Software Foundation; Seja a
 *              versao 3 da licenca, ou qualquer versao posterior.
 *
 *              Este programa e distribuido na esperanca de que seja util,
 *              mas SEM QUALQUER GARANTIA; Sem a garantia implicita de
 *              COMERCIALIZACAO OU USO PARA UM DETERMINADO PROPOSITO.
 *              Veja o site da "GNU General Public License" para mais detalhes.
 *
 * @htmlonly    http://www.gnu.org/copyleft/gpl.html
 */

#include <stdint.h>
#include <MKL25Z4.h>
#include <mkl_GPIO/mkl_GPIOPort.h>
#include <mkl_KeyboardParallelPort/mkl_KeyboardParallelPort.h>
#include "mkl_SystickPeriodicInterrupt/mkl_SystickPeriodicInterrupt.h"
#include "7segments/sevenSegments.h"

/*!
 * 	Declara��o do objeto Keyboard e configura��o das portas GPIO a serem utilizadas
 */
mkl_KeyboardParallelPort keyboard(gpio_PTC0, gpio_PTE5, gpio_PTE4, gpio_PTC3,
gpio_PTC4, gpio_PTC5, gpio_PTC6, gpio_PTC7);

/*! a
 * 	Declara��o do objeto systick e configura��o para acontecer uma interrup��o a cada 10ms
 * 	e usar o clock da placa de 42MHz
 */
mkl_SystickPeriodicInterrupt systick = mkl_SystickPeriodicInterrupt(10, clock42Mhz);

sevenSegments sevensegments = sevenSegments(gpio_PTA13, gpio_PTD5, gpio_PTD0, gpio_PTD2, gpio_PTE1, gpio_PTE3, gpio_PTB10,
		gpio_PTB3, gpio_PTE0, gpio_PTC2, gpio_PTB8);


/*!
 * 	Declara��o do led RGB interno da placa
 */
mkl_GPIOPort redLed(gpio_PTB18);

/*!
 * 	Declara��o do led RGB interno da placa
 */

/*!
 * 	Declara��o do led RGB interno da placa
 */
mkl_GPIOPort blueLed(gpio_PTD1); // position that refer to the HIGH in somewhere
mkl_GPIOPort greenLed(gpio_PTD3); // position to D1, first position in BCD
/*!

 * Declara��o da vari�vel a ser utilizada para armazenar a chave pressionada.
 */
char key;

//mkl_GPIOPort redLedoutput(gpio_PTB9);
//mkl_GPIOPort greenLedoutput(gpio_PTB8);

/*!
 *   @brief    Realiza as configura��es dos led's da placa bem como os inicia em modo off.
 */
void setupLED() {

	redLed.setPortMode(gpio_output);
	blueLed.setPortMode(gpio_output);
	greenLed.setPortMode(gpio_output);
	redLed.writeBit(1);
	blueLed.writeBit(1);
	greenLed.writeBit(1);
}

/*!
 *   @brief    Realiza o blink dos leds conforme a chave obtida.
 */
void setLED(){
	switch(key){
			case 0x0:
				sevensegments.turnOnSevenSegments(0, 4);
				break;
			case 0x1:
				sevensegments.turnOnSevenSegments(1, 4);
				break;
			case 0x2:
				sevensegments.turnOnSevenSegments(2, 4);
				break;
			case 0x3:
				sevensegments.turnOnSevenSegments(3, 4);
				break;
			case 0x4:
				sevensegments.turnOnSevenSegments(4, 4);
				break;
			case 0x5:				
				sevensegments.turnOnSevenSegments(5, 4);
				break;
			case 0x6:
				sevensegments.turnOnSevenSegments(6, 4);
				break;
			case 0x7:
				sevensegments.turnOnSevenSegments(7, 4);
				break;
			case 0x8:
				sevensegments.turnOnSevenSegments(8, 4);
				break;
			case 0x9:
				sevensegments.turnOnSevenSegments(9, 4);
				break;
			case 0xa:
				redLed.writeBit(0);blueLed.writeBit(1);greenLed.writeBit(1);
				break;
			case 0xb:
				redLed.writeBit(1);blueLed.writeBit(0);greenLed.writeBit(0);
				break;
			case 0xc:
				redLed.writeBit(1);blueLed.writeBit(0);greenLed.writeBit(1);
				break;
			case 0xd:
				redLed.writeBit(1);blueLed.writeBit(1);greenLed.writeBit(0);
				break;
			case 0xe:
				redLed.writeBit(0);blueLed.writeBit(0);greenLed.writeBit(0);
				break;
			case 0xf:
				redLed.writeBit(0);blueLed.writeBit(0);greenLed.writeBit(1);
				break;
			case 0x10:
				redLed.writeBit(1);blueLed.writeBit(1);greenLed.writeBit(1);
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

/*!
 *   @brief    Realiza a atualiza��o do teclado e obten��o da chave bem como chama a fun��o setLED.
 */
extern "C" {
    void SysTick_Handler(void) {
    	keyboard.update();
        key = keyboard.getKey();
        setLED();
    }
}


int main(){
	setupLED();


	systick.enableCounter();

	while(1){
		counterSevenSegments();
		//SysTick_Handler();
		//recepcao
	}
	return 0;
}


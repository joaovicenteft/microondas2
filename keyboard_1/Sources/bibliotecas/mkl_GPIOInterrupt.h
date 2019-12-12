/*!
* @copyright   � 2017 Universidade Federal do Amazonas.
*
* @brief       Uma API em C++ de interrup��es para GPIO.
*
* @file        mkl_GPIOInterrupt.h
* @version     1.0
* @date        6 Julho 2017
*
* @section     HARDWARES & SOFTWARES
*              +board        FRDM-KL25Z da NXP.
*              +processor    MKL25Z128VLK4 - ARM Cortex-M0+
*              +compiler     Kinetis� Design Studio IDE
*              +manual       L25P80M48SF0RM, Rev.3, September 2012
*              +revisions    Vers�o (data): Descri��o breve.
*                             ++ 1.0 (30 Julho 2017): Vers�o inicial.
*
* @section     AUTHORS & DEVELOPERS
*              +institution  Universidade Federal do Amazonas
*              +courses      Engenharia da Computa��o / Engenharia El�trica
*              +teacher      Miguel Grimm <miguelgrimm@gmail.com>
*              +student      Vers�o inicial:
*                             ++ Jos� Luis da Silva <joseluis70123@gmail.com>
*
* @section     LICENSE
*
*              GNU General Public License (GNU GPL)
*
*              Este programa � um software livre; Voc� pode redistribu�-lo
*              e/ou modific�-lo de acordo com os termos do "GNU General Public
*              License" como publicado pela Free Software Foundation; Seja a
*              vers�o 3 da licen�a, ou qualquer vers�o posterior.
*
*              Este programa � distribu�do na esperan�a de que seja �til,
*              mas SEM QUALQUER GARANTIA; Sem a garantia impl�cita de
*              COMERCIALIZA��O OU USO PARA UM DETERMINADO PROP�SITO.
*              Veja o site da "GNU General Public License" para mais detalhes.
*
* @htmlonly    http://www.gnu.org/copyleft/gpl.html
*/

#ifndef _HOME_GUILHERME_GPIOINTERRUPT_MKL_GPIOINTERRUPT_H_
#define _HOME_GUILHERME_GPIOINTERRUPT_MKL_GPIOINTERRUPT_H_

#include "mkl_GPIO.h"

typedef enum {
  gpio_whenLogicZero = 0b1000 << 16,
  gpio_onRisingEdge = 0b1001 << 16,
  gpio_onFallingEdge = 0b1010 << 16,
  gpio_onEitherEdge = 0b1011 << 16,
  gpio_whenLogicOne = 0b1100 << 16
} gpio_InterruptTrigger;

/*!
*  @class    mkl_GPIOInterrupt.
*
*  @brief    A classe implementa o perif�rico GPIO com interrup��o.
*
*  @details  Esta classe � derivada da classe m�e "mkl_GPIO" e implementa
*            o perif�rico GPIO com o modo de opera��o com interrup��o.
*
*/
class mkl_GPIOInterrupt: public mkl_GPIO {
 public:
 /*!
 * Construtor padr�o classe.
 */
  explicit mkl_GPIOInterrupt(gpio_Pin pin = gpio_PTA1);
 /*!
 * M�todos que tratam da interrup��o.
 */
  void getInterruptFlag();
  bool thisGpioTriggedIntr();
  void clearInterruptFlag();
  void enableInterrupt(gpio_InterruptTrigger interruptTrigger);
  void disableInterrupt();

 protected:
  volatile uint32_t *addressPortxISFR;

 private:
  uint32_t ISFR;
  IRQn_Type PORTx_IRQn;
  uint8_t bitPosition;
};
#endif  //  _HOME_GUILHERME_GPIOINTERRUPT_MKL_GPIOINTERRUPT_H_

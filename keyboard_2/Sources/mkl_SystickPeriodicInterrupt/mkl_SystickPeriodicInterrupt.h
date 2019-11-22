/*!
 * @copyright   � 2019 UFAM - Universidade Federal do Amazonas.
 *
 * @brief       Interface de programa��o de aplica��es em C++ para  o System Tick Timer (MKL25Z).
 *
 * @file        mkl_SystickPeriodicInterrupt.h
 * @version     1.0
 * @date        31 Janeiro 2019
 *
 * @section     HARDWARES & SOFTWARES
 *              +board        FRDM-KL25Z da NXP.
 *              +processor    MKL25Z128VLK4 - ARM Cortex-M0+.
 *              +peripheral   Systick - System Tick Timer.
 *              +compiler     Kinetis� Design Studio IDE
 *              +manual       L25P80M48SF0RM, Rev.3, September 2012
 *              +revisions    Vers�o (data): Descri��o breve.
 *                             ++ 1.0 (31 Janeiro 2019): Vers�o inicial.
 *
 * @section     AUTHORS & DEVELOPERS
 *              +institution  Universidade Federal do Amazonas
 *              +courses      Engenharia da Computa��o / Engenharia El�trica
 *              +teacher      Miguel Grimm <miguelgrimm@gmail.com>
 *              +student      Vers�o inicial:
 *                             ++ Victoria da Silva Leite <victoria.vl73@gmail.com>
 *
 * @section     LICENSE
 *
 *              GNU General Public License (GNU GPL).
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
#ifndef MKL_SYSTICKPERIODICINTERRUPT_H_
#define MKL_SYSTICKPERIODICINTERRUPT_H_

#include <stdint.h>
#include "../mkl_Systick/mkl_Systick.h"

/*!
 * Enum associado os n�veis de prioridade do TPM.
 */
typedef enum {
  systick_priority0 = 0,
  systick_priority1 = 1,
  systick_priority2 = 2,
  systick_priority3 = 3
} st_Priority_t;

/*!
 *  @class    mkl_GPIOPort.
 *
 *  @brief    A classe implementa o perif�rico GPIO sem interrup��o.
 *
 *  @details  Esta classe � derivada da classe m�e "mkl_GPIO" e implementa
 *            o perif�rico GPIO com o modo de opera��o sem interrup��o.
 *
 */

/*!
 *  @class    mkl_Systick
 *
 *  @brief    A classe mkl_Systick representa o perif�rico System Tick Timer da MKL25Z.
 *
 *  @details  Esta classe � derivada da classe m�e "mkl_Systick.h" e implementa a interrup��o
 *  		  do systick.
 *
 *  @section  EXAMPLES USAGE
 *
 *   Uso dos m�todos para o uso do Systick
 *     +fn mkl_SystickPeriodicInterrupt(uint32_t time_ms, systick_clockSource clock);
 *     +fn enableInterruptRequest();
 *     +fn disableInterruptRequest();
 *     +fn setPriority(st_Priority_t priority);
 *     +fn getPriority();
 *     +fn reloadValue(uint32_t time_ms, systick_clockSource clock);
 */
class mkl_SystickPeriodicInterrupt: public mkl_Systick {
 public:
	/*!
	 * Construtor padr�o da classe.
	 */
    mkl_SystickPeriodicInterrupt(uint32_t time_ms, systick_clockSource clock);
	/*!
	 * M�todos que configuram a interrup��o
	 */
    void enableInterruptRequest();
    void disableInterruptRequest();
    void setPriority(st_Priority_t priority);
    st_Priority_t getPriority();

 private:
	/*!
	 * M�todo interno para calcular o valor de reload relativo ao tempo em milisegundos.
	 */
    uint32_t reloadValue(uint32_t time_ms, systick_clockSource clock);
};

#endif  // MKL_SYSTICKPERIODICINTERRUPT_H_

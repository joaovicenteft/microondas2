/*!
 * @copyright   � 2019 Universidade Federal do Amazonas.
 *
 * @brief       Interface da API em C++ da classe m�e KeyboardParallelPort.
 *
 * @file        mkl_KeyboardParallelPort.h
 * @version     1.0
 * @date        04 mar�o 2019
 *
 * @section     HARDWARES & SOFTWARES
 *              +board        FRDM-KL25Z da NXP.
 *              +processor    MKL25Z128VLK4 - ARM Cortex-M0+
 *              +compiler     Kinetis� Design Studio IDE
 *              +manual       L25P80M48SF0RM, Rev.3, September 2012
 *              +revisions    Vers�o (data): Descri��o breve.
 *                             ++ 1.0 (04 Mar�o 2019): Vers�o inicial.
 *
 * @section     AUTHORS & DEVELOPERS
 *              +institution  Universidade Federal do Amazonas
 *              +courses      Engenharia da Computa��o / Engenharia El�trica
 *              +teacher      Miguel Grimm <miguelgrimm@gmail.com>
 *              +student      Vers�o inicial:
 *                             ++ Daniel Modesto de Souza <daniel.modesto.dmds@gmail.com>
 *
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

#include "../mkl_GPIO/mkl_GPIOPort.h"
#include "MKL25Z4.h"

class mkl_KeyboardParallelPort{
 public:

	mkl_KeyboardParallelPort(gpio_Pin pL0, gpio_Pin pL1, gpio_Pin pL2,gpio_Pin pL3,
	 gpio_Pin pC0, gpio_Pin pC1, gpio_Pin pC2, gpio_Pin pC3);

	 /*!
	   * M�todo que verifica se uma chave foi pressionada.
	   */
	bool keyIsPressed();

	 /*!
	   * M�todo que retorna a chave pressionada.
	   */
	char getKey();

	 /*!
	   * M�todo que atualiza a leitura do teclado.
	   */
	void update();

private:
	/*!
	  * Vari�vel de armazenamento da chave.
	  */
	char key;

	/*!
	  * Objetos instanciados da classe mkl_GPIOPort.
	  */
	mkl_GPIOPort L0, L1, L2, L3, C0, C1, C2, C3;
};



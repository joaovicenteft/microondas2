/*!
 * @copyright   � 2019 Universidade Federal do Amazonas.
 *
 * @brief       Interface da API em C++ da classe m�e mkl_KeyboardParallelPort.
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

#include "mkl_KeyboardParallelPort.h"
#include "../mkl_GPIO/mkl_GPIOPort.h"

/*!
 *   @fn		mkl_KeyboardParallelPort
 *
 * 	 @brief		Construtor padr�o da classe.O construtor padr�o da classe configura as portas GPIO, define estas como entrada e ativa resistores de pull-up
 *
 *	 @param[in] pinL0-pinL3 - Portas GPIO a serem utilizadas no teclado como linhas.
 *	 			pinC0-pinC3 - Portas GPIO a serem utilizadas no teclado como colunas.
 */
mkl_KeyboardParallelPort::mkl_KeyboardParallelPort(gpio_Pin pinL0, gpio_Pin pinL1, gpio_Pin pinL2,gpio_Pin pinL3, gpio_Pin pinC0, gpio_Pin pinC1, gpio_Pin pinC2, gpio_Pin pinC3){
    /*
     * Define as portas gpio das linhas e colunas
     */
    L0 = mkl_GPIOPort(pinL0);
    L1 = mkl_GPIOPort(pinL1);
    L2 = mkl_GPIOPort(pinL2);
    L3 = mkl_GPIOPort(pinL3);
    C0 = mkl_GPIOPort(pinC0);
    C1 = mkl_GPIOPort(pinC1);
    C2 = mkl_GPIOPort(pinC2);
    C3 = mkl_GPIOPort(pinC3);
    /*
     * Configura o resistor pull-up de cada porta associada a colunas
     */
    C0.setPullResistor(gpio_pullUpResistor);
    C1.setPullResistor(gpio_pullUpResistor);
    C2.setPullResistor(gpio_pullUpResistor);
    C3.setPullResistor(gpio_pullUpResistor);
    /*
     * Configura como entrada todas as portas
     */
    L0.setPortMode(gpio_input);
    L1.setPortMode(gpio_input);
    L2.setPortMode(gpio_input);
    L3.setPortMode(gpio_input);
    C0.setPortMode(gpio_input);
    C1.setPortMode(gpio_input);
    C2.setPortMode(gpio_input);
    C3.setPortMode(gpio_input);

}

/*!
 *   @fn		update
 *
 * 	 @brief 	Atualiza a leitura do teclado matricial
 */

void mkl_KeyboardParallelPort::update()
{
    int row = -2, col = -2;

    	L0.setPortMode(gpio_output);
    	L1.setPortMode(gpio_input);
    	L2.setPortMode(gpio_input);
    	L3.setPortMode(gpio_input);
    	L0.writeBit(0);
    	if(C0.readBit() == 0){
    		col = 0;
    		row = 0;
    	}
    	else if(C1.readBit() == 0){
    		col = 1;
    		row = 0;
    	}
    	else if(C2.readBit() == 0){
    		col = 2;
    		row = 0;
    	}
    	else if(C3.readBit() == 0){
    		col = 3;
    		row = 0;
    	}

    if(row == -2){
    	L0.setPortMode(gpio_input);
    	L1.setPortMode(gpio_output);
    	L2.setPortMode(gpio_input);
    	L3.setPortMode(gpio_input);
    	L1.writeBit(0);
    	if(C0.readBit() == 0){
    		col = 0;
    		row = 1;
    	}
    	else if(C1.readBit() == 0){
    		col = 1;
    		row = 1;
    	}
    	else if(C2.readBit() == 0){
    		col = 2;
    		row = 1;
    	}
    	else if(C3.readBit() == 0){
    		col = 3;
    		row = 1;
    	}
    }

    if(row == -2){
    	L0.setPortMode(gpio_input);
    	L1.setPortMode(gpio_input);
    	L2.setPortMode(gpio_output);
    	L3.setPortMode(gpio_input);
    	L2.writeBit(0);
    	if(C0.readBit() == 0){
    		col = 0;
    		row = 2;
    	}
    	else if(C1.readBit() == 0){
    		col = 1;
    		row = 2;
    	}
    	else if(C2.readBit() == 0){
    		col = 2;
    		row = 2;
    	}
    	else if(C3.readBit() == 0){
    		col = 3;
    		row = 2;
    	}
    }

    if(row == -2){
    	L0.setPortMode(gpio_input);
    	L1.setPortMode(gpio_input);
    	L2.setPortMode(gpio_input);
    	L3.setPortMode(gpio_output);
    	L3.writeBit(0);
    	if(C0.readBit() == 0){
    		col = 0;
    		row = 3;
    	}
    	else if(C1.readBit() == 0){
    		col = 1;
    		row = 3;
    	}
    	else if(C2.readBit() == 0){
    		col = 2;
    		row = 3;
    	}
    	else if(C3.readBit() == 0){
    		col = 3;
    		row = 3;
    	}
    }

    if(row == -2)key = 16;
    if(col == 0 and row!= 3)key = row*3 + 1;
    if(col == 1 and row!= 3)key = row*3 + 2;
    if(col == 2 and row!= 3)key = row*3 + 3;
    if(col == 3)key = row + 10;
    if(col == 0 and row == 3)key = 14;
    if(col == 1 and row == 3)key = 0;
    if(col == 2 and row == 3)key = 15;
}

/*!
 *   @fn		keyIsPressed
 *
 * 	 @brief 	Verifica se alguma chave foi pressionada ou n�o
 */
bool mkl_KeyboardParallelPort::keyIsPressed()
{
	if(getKey() == 16)
	return false;
	else
	return true;
}

/*!
 *   @fn		getKey
 *
 * 	 @brief 	Retorna a chave pressionada no �ltimo update
 */
char mkl_KeyboardParallelPort::getKey(){return key;}



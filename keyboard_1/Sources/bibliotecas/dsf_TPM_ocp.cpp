/*!
 * @copyright   � 2017 UFAM - Universidade Federal do Amazonas.
 *
 * @brief       Implementa��o da classe m�e "dsf_TPMPeripheral_ocp".
 *
 * @file        dsf_TPM_ocp.cpp
 * @version     1.0
 * @date        02 Agosto 2017
 *
 * @section     HARDWARES & SOFTWARES
 *              +board        FRDM-KL25Z da NXP.
 *              +processor    MKL25Z128VLK4 - ARM Cortex-M0+.
 *              +peripheral   TPM.
 *              +compiler     Kinetis� Design Studio IDE.
 *              +manual       L25P80M48SF0RM, Rev.3, September 2012.
 *              +revisions    Vers�o (data): Descri��o breve.
 *                             ++ 1.0 (02 Agosto 2017): Vers�o inicial.
 *
 * @section     AUTHORS & DEVELOPERS
 *              +institution  Universidade Federal do Amazonas.
 *              +courses      Engenharia da Computa��o / Engenharia El�trica.
 *              +teacher      Miguel Grimm <miguelgrimm@gmail.com>
 *              +student      Vers�o inicial:
 *                             ++ Hamilton Nascimento <hdan_neto@hotmail.com>
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

#include "dsf_TPM_ocp.h"

/*!
 *   @fn         bindPeripheral
 *
 *   @brief      Associa o objeto de software ao perif�rico de hardware.
 *
 *   Este m�todo associa ao objeto de software o perif�rico de hardware,
 *   utilizando a inicializa��o dos ponteiros para os endere�os de mem�ria
 *   dos registradores correspondentes.
 *
 *   @param[in]  baseAddress - o endere�o base do perif�rico TPM.
 *
 *   @remarks    Sigla e pagina do Manual de Referencia KL25:
 *               - TPMxSC: Status Control Register. P�g. 552.
 *               - TPMxCNT: Counter Register. P�g.554.
 *               - TPMxMOD: Modulo Register. P�g. 554.
 */

void dsf_TPMPeripheral_ocp::bindPeripheral(uint8_t *baseAddress) {
  addressTPMxSC = (volatile uint32_t *)(baseAddress);
  addressTPMxCNT = (volatile uint32_t *)(baseAddress + 0x4);
  addressTPMxMOD = (volatile uint32_t *)(baseAddress + 0x8);
}

/*!
 *   @fn         bindChannel
 *
 *   @brief      Associa o canal do objeto de software ao hardware
 *
 *   Este m�todo associa os atributos do canal do objeto de software ao
 *   seu correspondente do perif�rico hardware.
 *
 *   @param[in]  baseAddress - o endere�o base do perif�rico TPM.
 *               chnNumber - o n�mero do canal do perif�rico TPM.
 *
 *   @remarks    Sigla e pagina do Manual de Referencia KL25:
 *               - TPMxCnV: Channel Value Register. P�g.557.
 *               - TPMxCnSC: Channel Status Control Register. P�g.555.
 */
void dsf_TPMPeripheral_ocp::bindChannel(uint8_t *baseAddress,
                                        uint8_t chnNumber) {
  addressTPMxCnV = (volatile uint32_t *)(baseAddress + 0x10 + 8*chnNumber);
  addressTPMxCnSC = (volatile uint32_t *)(baseAddress + 0xC + 8*chnNumber);
}


/*!
 *   @fn         bindPin
 *
 *   @brief      Associa o pino do objeto ao perif�rico de hardare.
 *
 *   Este m�todo associa o pino do objeto de software ao pino do perif�rico.
 *
 *   @param[in]  pinNumber - o n�mero do pino do objeto de software.
 *
 *   @remarks    Sigla e pagina do Manual de Referencia KL25:
 *               - PCR: Pin Control Register. P�g.183.
 */
void dsf_TPMPeripheral_ocp::bindPin(uint8_t GPIONumber, uint8_t pinNumber) {
  addressPortxPCRn = (volatile uint32_t *)(0x40049000
                                          + 0x1000*GPIONumber + 4*pinNumber);
}


/*!
 *   @fn         enablePeripheralClock
 *
 *   @brief      Habilita o clock do perif�rico de hardware.
 *
 *   Este m�todo habilita o clock do perif�rico TPM solicitado.
 *
 *   @remarks    Sigla e pagina do Manual de Referencia KL25:
 *               - SCGC6: System Control Gating Clock Register 6. P�g.207.
 *               - SOPT2: System Options Register 2. P�g.195.
 */
void dsf_TPMPeripheral_ocp::enablePeripheralClock(uint8_t TPMNumber) {
  SIM_SCGC6 |= SIM_SCGC6_TPM0_MASK << TPMNumber;
  SIM_SOPT2 |= SIM_SOPT2_TPMSRC(1);
}

/*!
 *   @fn         enableGPIOClock
 *
 *   @brief      Habilita o clock do GPIO do pino.
 *
 *   Este m�todo habilita o clock do perif�rico GPIO do pino passado por
 *   par�metro.
 *
 *   @param[in]  GPIONumber - o n�mero do GPIO correspondente ao pino.
 *
 *   @remarks    Sigla e pagina do Manual de Referencia KL25:
 *               - SCGC5: System Control Gating Clock Register 5. P�g.199.
 */
void dsf_TPMPeripheral_ocp::enableGPIOClock(uint8_t GPIONumber) {
  SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK << GPIONumber;
}

/*!
 *   @fn         selectMuxAlternative
 *
 *   @brief      Seleciona a alternativa de trabalho do pino.
 *
 *   Este m�todo seleciona o modo de opera��o do pino correspondente para o
 *   modo de opera��o TPM.
 *
 *   @param[in]  muxAlt - alternativa de opera��o do pino para o canal e TPM
 *                        especificados.
 *
 *   @remarks    Sigla e pagina do Manual de Referencia KL25:
 *               - PCR: Pin Control Register. P�g.183.
 */
void dsf_TPMPeripheral_ocp::selectMuxAlternative(uint8_t muxAlt) {
  *addressPortxPCRn = PORT_PCR_MUX(muxAlt);
}

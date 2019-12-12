#include "switch.h"

switche::switche(gpio_Pin pino) {
	chave=mkl_GPIOPort(pino);
	chave.setPortMode(gpio_input);
	chave.setPullResistor(gpio_pullUpResistor);

	atualState=wait_for_press;
}
int switche::read(){
	return chave.readBit();
}
int switche::isOn(){
	switch(atualState){
		case wait_for_press:
			if(read()==0){
				atualState=while_pressed;
			}
			break;
		case while_pressed:
			if (read()==1){
				atualState=send_data;
			}
			break;
		case send_data:
			atualState=wait_for_press;
			break;
	}

	if(atualState == wait_for_press || atualState == while_pressed){
		return 0;
	} else if (atualState == send_data){
		return 1;
	}
}


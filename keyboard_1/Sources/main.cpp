#include <stdint.h>
#include <MKL25Z4.h>
#include "teclado/mkl_KeyboardParallelPort.h"
#include "bibliotecas/mkl_SystickPeriodicInterrupt.h"
#include "dispositivos/led.h"
#include "dispositivos/switch.h"
#include "dispositivos/displaySegments.h"
#include "servicos/EditService.h"
#include "servicos/IncrementService.h"

mkl_KeyboardParallelPort keyboard(gpio_PTA13, gpio_PTD5, gpio_PTD0, gpio_PTD2,
gpio_PTC12, gpio_PTC13, gpio_PTC16, gpio_PTC17);

displaySegments display (gpio_PTC7,gpio_PTC0,gpio_PTC3,gpio_PTC4,gpio_PTC5,gpio_PTC6,gpio_PTC10,gpio_PTA12,gpio_PTA4,gpio_PTA5,gpio_PTC8);

led press(gpio_PTD3);

mkl_SystickPeriodicInterrupt systick = mkl_SystickPeriodicInterrupt(10, clock42Mhz);

registrador Us(0);
registrador Ds(0);
registrador Um(0);
registrador Dm(0);

switche botao3(gpio_PTA2),botao7(gpio_PTD4);

switche permission(gpio_PTA1);

controlador service_edit;

IncrementService service_inc;

char key;
int valor=0;

extern "C" {
    void SysTick_Handler(void) {
    	keyboard.update();
        key = keyboard.getKey();
        if(keyboard.keyIsPressed()){
        	press.on();
        	valor=key;
        }
        else{
        	press.off();
        }
    }
}

void setup(){
	press.off();

}
int main(){
	setup();
	while(1){
		service_edit.maq_est(keyboard.keyIsPressed(),!permission.read());
		service_edit.select_service();
		service_edit.do_service(&Dm,&Um,&Ds,&Us,valor);



    	service_inc.machineState(botao3.isOn(),botao7.isOn(),!permission.read());
    	service_inc.selectService();
    	service_inc.doService(&Dm,&Um,&Ds,&Us);

    	display.monitora(Us.leValor(),Ds.leValor(),Um.leValor(),Dm.leValor());


	}
	return 0;
}


#include "../bibliotecas/mkl_GPIOPort.h"
#include "../bibliotecas/dsf_Delay_ocp.h"
class displaySegments {


public:
	displaySegments(gpio_Pin pinoA,gpio_Pin pinoB,gpio_Pin pinoC,
			gpio_Pin pinoD,gpio_Pin pinoE,gpio_Pin pinoF,gpio_Pin pinoG, gpio_Pin pinoDig1,
			 gpio_Pin pinDig2,  gpio_Pin pinDig3,  gpio_Pin pinDig4);

	void seta_segmento(int key);
	void digito(int key, int position);
	void monitora(int key1, int key2, int key3, int key4);

private:
	mkl_GPIOPort D1;
	mkl_GPIOPort D2;
	mkl_GPIOPort D3;
	mkl_GPIOPort D4;
	mkl_GPIOPort sega;
	mkl_GPIOPort segb;
	mkl_GPIOPort segc;
	mkl_GPIOPort segd;
	mkl_GPIOPort sege;
	mkl_GPIOPort segf;
	mkl_GPIOPort segg;
};

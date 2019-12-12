//#include "digitalFactory.h"
#include "../digitais/registrador.h"


typedef enum{
	wait_for_full2=0,
	ask_permission=1,
	wait_permission2=2,
	load_value=3,
	end_state=4
}estados2;


class IncrementService{

public:
	explicit IncrementService();
	void recebeIncremento(registrador *reg4,registrador *reg3,registrador *reg2,registrador *reg1);
	void machineState(bool b3, bool b7, bool permission);
	void selectService();
	void doService(registrador *reg4,registrador *reg3,registrador *reg2,registrador *reg1);
private:
	bool endService;
	bool permission;
	estados2 stateService;
	int valueIncrement;
	int servico;
};

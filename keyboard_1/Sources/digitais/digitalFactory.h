#include "registrador.h"
#include "servicos/EditService.h"
#include "servicos/IncrementService.h"

class digitalFactory {

    private:
        controlador editservice;
        IncrementService incrementservice;

    public:
        void createDigitalFactory();
};

#include "stdint.h"

typedef enum {
    stOff = 0,
    stOn
} state_t;

typedef enum {q1, q2, q3, q4, q5} states_t;

typedef enum {q1, q2, q3} states_debouncer;

class editionService {

    public:
        states_t states = q1;

    private:
        char key;
        int buttonTurnOn;
        int buttonIsPressedKey;
        int buttonIsPressedKeyFinished;
        int reg[4];

    public:

        void setKey(char key);
        void setReg(int reg1, int reg2, int reg3, int reg4);
        void setButtonTurnOn(int buttonTurnOn);
        void setButtonIsPressedKey(int buttonIsPressedKey);

        int getButtonTurnOn();
        int getButtonIsPressedKey();
        int getRegByPosition(int position);
        char getKey();
        
        state_t eventBon();
        void nextState();
        void doActivies();
        void debouncerKey();
        int verifiyKeyboardAndConversion(char key);
};
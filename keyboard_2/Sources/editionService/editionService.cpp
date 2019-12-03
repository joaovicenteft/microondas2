#include "editionService.h"
#include "7segments/sevenSegments.h"

void editionService::setKey(char key) {
    this->key = key;
}

void editionService::setReg(int reg1, int reg2, int reg3, int reg4) {
    reg[0] = reg1;
    reg[1] = reg2;
    reg[2] = reg3;
    reg[3] = reg4;
}

void editionService::setButtonTurnOn(int buttonTurnOn) {
    this->buttonTurnOn = buttonTurnOn;
}

void editionService::setButtonIsPressedKey(int buttonIsPressedKey) {
    this->buttonIsPressedKey = buttonIsPressedKey;
}

int editionService::getRegByPosition(int position) {
    return reg[position];
}

int editionService::getButtonTurnOn() {
    return buttonIsPressedKey;
}

int editionService::getButtonIsPressedKey() {
    return buttonIsPressedKey;
}

int editionService::verifiyKeyboardAndConversion(char key) {

	switch (key) {
			case 0x0:
				return 0;
			case 0x1:
				return 1;
			case 0x2:
				return 2;
			case 0x3:
				return 3;
			case 0x4:
				return 4;
			case 0x5:
				return 5;
			case 0x6:
				return 6;
			case 0x7:
				return 7;
			case 0x8:
				return 8;
			case 0x9:
				return 9;
	}
}

char editionService::getKey() {
    return key;
}

void editionService::debouncerKey() {
    states_debouncer states = q1;

    switch (states) {
        case q1:
            buttonIsPressedKeyFinished = 0;
            if (buttonIsPressedKey)
                states = q2;
            else
                states = q1;
        case q2:
            buttonIsPressedKeyFinished = 0;
            if (!buttonIsPressedKey)
                states = q3;
            else
                states = q2;
        case q3:
            buttonIsPressedKeyFinished = 1;
    }
}


void editionService::nextState() {
    
    switch (states) {
        case q1:
            if (buttonTurnOn)
                states = q2;
            else
                states = q1;
            break;
        case q2:
            debouncerKey();
            if (buttonIsPressedKeyFinished)
                states = q3:
            else
                states = q2;
            break;
        case q3:
            debouncerKey();
            if (buttonIsPressedKeyFinished)
                states = q4;
            else
                states = q3;
            break;
        case q4:
            debouncerKey();
            if (buttonIsPressedKeyFinished)
                states = q5;
            else
                states = q4;
            break;
        case q5:
            debouncerKey();
            if (buttonIsPressedKeyFinished)
                states = q6;
            else
                states = q5;
            break;
        case q6:
            debouncerKey();
            if (buttonIsPressedKeyFinished)
                states = q1;
            else
                states = q6;
            break;
    }
}



editionService::doActivies() {

    switch (states) {
        case q1:
            break;
        case q2:
            int lastNumber = verifiyKeyboardAndConversion(key);
            setReg(0, 0, 0, lastNumber);
            
            break;
        case q3:
            int lastNumber = verifiyKeyboardAndConversion(key);
            setReg(0, 0, getRegByPosition(3), lastNumber);

            break;
        case q4:
            int lastNumber = verifiyKeyboardAndConversion(key);
            setReg(0, getRegByPosition(2), getRegByPosition(3), lastNumber);

           break;
        case q5:
            int lastNumber = verifiyKeyboardAndConversion(key);
            setReg(getRegByPosition(1), getRegByPosition(2), getRegByPosition(3), lastNumber); 
            
            break;
    }
}

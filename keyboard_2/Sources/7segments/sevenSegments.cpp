#include "sevenSegments.h"

sevenSegments::sevenSegments(gpio_Pin pa, gpio_Pin pb, gpio_Pin pc, gpio_Pin pd,
		gpio_Pin pe, gpio_Pin pf, gpio_Pin pg, gpio_Pin pD1, gpio_Pin pD2, gpio_Pin pD3, gpio_Pin pD4) {


        a = mkl_GPIOPort(pa);
        b = mkl_GPIOPort(pb);
        c = mkl_GPIOPort(pc);
        d = mkl_GPIOPort(pd);
        e = mkl_GPIOPort(pe);
        f = mkl_GPIOPort(pf);
        g = mkl_GPIOPort(pg);

        D1 = mkl_GPIOPort(pD1);
        D2 = mkl_GPIOPort(pD2);
        D3 = mkl_GPIOPort(pD3);
        D4 = mkl_GPIOPort(pD4);       
            
        a.setPortMode(gpio_output);
        b.setPortMode(gpio_output);
        c.setPortMode(gpio_output);
        d.setPortMode(gpio_output);
        e.setPortMode(gpio_output);
        f.setPortMode(gpio_output);
        g.setPortMode(gpio_output);
        D1.setPortMode(gpio_output);
        D2.setPortMode(gpio_output);
        D3.setPortMode(gpio_output);
        D4.setPortMode(gpio_output);

}

void sevenSegments::clear() {
    a.writeBit(0);
    b.writeBit(0);
    c.writeBit(0);
    d.writeBit(0);
    e.writeBit(0);
    f.writeBit(0);
    g.writeBit(0);
}

void sevenSegments::zero() {
    a.writeBit(0);
    b.writeBit(0);
    c.writeBit(0);
    d.writeBit(0);
    e.writeBit(0);
    f.writeBit(0);
    g.writeBit(1);
}

void sevenSegments::one() {
    a.writeBit(1);
    b.writeBit(0);
    c.writeBit(0);
    d.writeBit(1);
    e.writeBit(1);
    f.writeBit(1);
    g.writeBit(1);
}

void sevenSegments::two() {
    a.writeBit(0);
    b.writeBit(0);
    c.writeBit(1);
    d.writeBit(0);
    e.writeBit(0);
    f.writeBit(1);
    g.writeBit(0);
}

void sevenSegments::three() {
    a.writeBit(0);
    b.writeBit(0);
    c.writeBit(0);
    d.writeBit(0);
    e.writeBit(1);
    f.writeBit(1);
    g.writeBit(0);
}

void sevenSegments::four() {
    a.writeBit(1);
    b.writeBit(0);
    c.writeBit(0);
    d.writeBit(1);
    e.writeBit(1);
    f.writeBit(0);
    g.writeBit(0);
}

void sevenSegments::five() {
    a.writeBit(0);
    b.writeBit(1);
    c.writeBit(0);
    d.writeBit(0);
    e.writeBit(1);
    f.writeBit(0);
    g.writeBit(0);
}

void sevenSegments::six() {
    a.writeBit(0);
    b.writeBit(1);
    c.writeBit(0);
    d.writeBit(0);
    e.writeBit(0);
    f.writeBit(0);
    g.writeBit(0);
}

void sevenSegments::seven() {
    a.writeBit(0);
    b.writeBit(0);
    c.writeBit(0);
    d.writeBit(1);
    e.writeBit(1);
    f.writeBit(1);
    g.writeBit(1);
}

void sevenSegments::eight() {
    a.writeBit(0);
    b.writeBit(0);
    c.writeBit(0);
    d.writeBit(0);
    e.writeBit(0);
    f.writeBit(0);
    g.writeBit(0);
}

void sevenSegments::nine() {
    a.writeBit(0);
    b.writeBit(0);
    c.writeBit(0);
    d.writeBit(0);
    e.writeBit(1);
    f.writeBit(0);
    g.writeBit(0);
}

void sevenSegments::turnOnSevenSegments(int number, int position) {

    switch (position) {
        case 1:
            D1.writeBit(1);
            break;
        case 2:
            D2.writeBit(1);
            break;
        case 3:
            D3.writeBit(1);
            break;
        case 4:
            D4.writeBit(1);
            break;
    }



    switch (number) {
    case 1:
        one();
        break;
    case 2:
        two();
        break;
    case 3:
        three();
        break;
    case 4:
        four();
        break;
    case 5:
        five();
        break;
    case 6:
        six();
        break;
    case 7:
        seven();
        break;
    case 8:
        eight();
        break;
    case 9:
        nine();
        break;
    
    default:
        zero();
        break;
    }

}




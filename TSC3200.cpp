#include "Arduino.h"
#include "TSC3200.h"

TSC3200::TSC3200(int _s0, int _s1, int _s2, int _s3, int _out) {
    s0=_s0;
    s1=_s1;
    s2=_s2;
    s3=_s3;
    out=_out;
    pinMode(s0, OUTPUT);
    pinMode(s1, OUTPUT);
    pinMode(s2, OUTPUT);
    pinMode(s3, OUTPUT);
    pinMode(out, INPUT);
}

void TSC3200::begin() {
    digitalWrite(s0, HIGH);
    digitalWrite(s1, HIGH);
}

void TSC3200::readColor() {
    digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);                                           
    red=pulseIn(out, digitalRead(out)==HIGH?LOW:HIGH);
    delay(20);  
    digitalWrite(s3, HIGH);                                         
    blue=pulseIn(out, digitalRead(out)==HIGH?LOW:HIGH);
    delay(20);  
    digitalWrite(s2, HIGH);  
    green=pulseIn(out, digitalRead(out)==HIGH?LOW:HIGH);
    delay(20); 
}

String TSC3200::colorName() {
    if(red<=15 && blue<=15 && green<=15) {
        return "White";
    }else if(red<blue && red<=green && red<23) {
        return "Red";
    }else if(blue<red && blue<green && blue<20) {
        return "Blue";
    }else if(green<red && green-blue<=8) {
        return "Green";
    }else {
        return "Unknown";
    }
}
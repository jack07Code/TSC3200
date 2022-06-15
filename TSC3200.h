#ifndef TSC3200_h
#define TSC3200_h

#include "Arduino.h"

class TSC3200 {
    public:
        TSC3200(int _s0, int _s1, int _s2, int _s3, int out);
        int red=0;
        int blue=0;
        int green=0;
        void readColor();
        void begin();
        String colorName();
    private:
        int s0;
        int s1;
        int s2;
        int s3;
        int out;
}

#endif
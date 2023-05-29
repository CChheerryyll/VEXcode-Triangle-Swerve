#include "module.h"
#include "constants.h"

#ifndef TSWERVE_H
#define TSWERVE_H

class Tswerve {
    public:

    Module ModR, ModG, ModB;

    Tswerve();
    
    Tswerve(Module r, Module g, Module b);

    void basicDrive();

};

#endif
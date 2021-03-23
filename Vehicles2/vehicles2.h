#pragma once

#include <vector>
#include <array>
#include <iostream>

#include "vehicles1b.h"

using namespace std;
using namespace v1;

namespace v2
{
    // Wheel
    struct Wheel
    {
        int         serialNumber;
        Tyre        tyre;
        
        static int nextSerialNumber;
        Wheel() : serialNumber(nextSerialNumber++) { cout << "I'm wheel #" << serialNumber << endl; }
        ~Wheel() { cout << "I was wheel #" << serialNumber << endl; }
    };

    // FlexibleCar: you can add more wheels at any time
    struct FlexibleCar
    {
        Engine          engine;
        vector<Wheel>   wheels;
        
        FlexibleCar(int numWheels) { wheels.resize(numWheels); }
        void addWheels(int numExtraWheels) { wheels.resize(wheels.size() + numExtraWheels); }
    };
    
    void testMe();
}


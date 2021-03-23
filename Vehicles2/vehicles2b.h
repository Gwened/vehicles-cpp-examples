#pragma once

#include <vector>
#include <array>
#include <iostream>

#include "vehicles1b.h"

using namespace std;
using namespace v1;

namespace v2
{
    const int UnassignedSerialNumber = -1;

    // Wheel
    struct Wheel
    {
        int         serialNumber;
        Tyre        tyre;
        
        static int nextSerialNumber;
        Wheel() : serialNumber(nextSerialNumber++) { cout << "I'm wheel #" << serialNumber << endl; }
        Wheel(const Wheel& w) : serialNumber(nextSerialNumber++), tyre(w.tyre) { cout << "I'm clone #" << serialNumber << endl; }
        Wheel(Wheel&& w) noexcept : serialNumber(w.serialNumber), tyre(w.tyre)
        {
            w.serialNumber = UnassignedSerialNumber;
            cout << "I'm moving wheel #" << serialNumber << endl;
        }
        Wheel& operator=(Wheel&& w)
        {
            if (this != &w)
            {
                serialNumber = w.serialNumber;
                tyre = w.tyre;
                w.serialNumber = UnassignedSerialNumber;
                cout << "I'm moving wheel #" << serialNumber << endl;
            }
            return *this;
        }
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


#pragma once

#include <vector>
#include <array>
#include <iostream>

using namespace std;

namespace v1
{
    // Engine
    struct Engine
    {
        const float horsepower = 100.f;
    };
    
    // Wheel
    struct Tyre
    {
        float frictionCoeff = 0.01;    
    };
    struct Wheel
    {
        int         serialNumber;
        Tyre        tyre;
        
        static int nextSerialNumber;
    };
    
    // Car = Engine + Wheels
    struct Car
    {
        Engine          engine;
        array<Wheel, 4> wheels;
    };
    
    void testMe();
}


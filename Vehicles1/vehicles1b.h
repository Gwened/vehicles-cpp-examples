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
        Wheel() : serialNumber(nextSerialNumber++) { cout << "I'm wheel #" << serialNumber << endl; }
        ~Wheel() { cout << "I was wheel #" << serialNumber << endl; }
    };
    
    // Car = Engine + Wheels
    template <int NumWheels>
    struct Car
    {
        Engine                  engine;
        array<Wheel, NumWheels> wheels;
        
        void accelerate() { cout << "Vrooom" << endl; }
        void setReverse(bool r) { cout << "Crrrc" << endl; }
    };
    
    void testMe();
}


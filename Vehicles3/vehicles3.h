#pragma once

#include <vector>
#include <array>
#include <iostream>
#include <memory>
#include <string>

#include "vehicles2b.h"

using namespace std;
using namespace v1;
using namespace v2;

namespace v3
{
    /*
     * Attempt #1: no code factorization
     */

    struct Wing
    {
        const float winspan = 3.f;
        float flex = 0.f;
    };
    
    struct SmallAircraftA
    {
        Engine                  engine;
        array<v2::Wheel, 3>     wheels;
        array<Wing, 2>          wings;

        void accelerate() { cout << "Rrrroar" << endl; }
    };
    











    /*
     * Attempt #2: Inheritance where Liskov is broken
     */

    struct SmallAircraftB : public Car<3>
    {
        array<Wing, 2>            wings;
        
        void accelerate() { Car<3>::accelerate(); cout << "and rrroar" << endl; }
        void setReverse(bool r); // wtf!?
    };
    











    /*
     * Attempt #3: Inheritance with base class
     */

    template <int NumWheels>
    struct Vehicle
    {
        Engine                        engine;
        array<v2::Wheel, NumWheels>   wheels;
        
        void accelerate() { cout << "Shhhh" << endl; }
    };
    
    struct CarB : public Vehicle<4>
    {
        void accelerate() { cout << "Vrooom" << endl; }
        void setReverse(bool r);
    };
    
    struct SmallAircraftC : public Vehicle<3>
    {
        array<Wing, 2>            wings;

        void accelerate() { cout << "Rrrroar" << endl; }
    };
    
    struct Glider : public Vehicle<3>
    {
        // Ooop, I've got a useless engine
    };
    






    /*
     * Towing vehicles attempt #1: only cars
     */

    struct TrailerCarA : public Car<4>
    {
        const TrailerCarA *    towedCar;
        TrailerCarA& tow(const TrailerCarA& c)
        {
            towedCar = &c;
            return *this;
        }
    };













    /*
     * Towing vehicles attempt #2: inheritance from base class
     */

    template <int NumWheels>
    struct TrailerVehicle : public Vehicle<NumWheels>
    {
        const Vehicle<NumWheels> *     towedVehicle;
        
        TrailerVehicle& tow(const Vehicle<NumWheels>& v)
        {
            cout << "Towing" << endl;
            towedVehicle = &v;
            return *this;
        }
    };
    
    struct TrailerCarB : public TrailerVehicle<4>
    {
        void setReverse(bool r) { cout << "Crrrc" << endl; }
    };
    












    /*
     * Towing vehicles attempt #3: using interfaces
     */

    struct IVehicle
    {
        virtual void accelerate() = 0;
    };

    struct IReversable
    {
        virtual void setReverse(bool r) = 0;
    };

    struct ITowable
    {
        virtual ITowable& tow(const IVehicle& v) = 0;
    };

    template <int NumWheels>
    struct TrailerVehicleC : public IVehicle, public ITowable, private Vehicle<NumWheels>
    {
        const IVehicle *     towedVehicle;
        
        // Implement the IVehicle interface
        void accelerate() override { Vehicle<NumWheels>::accelerate(); }

        // Implement the ITowable interface
        TrailerVehicleC& tow(const IVehicle& v) override
        {
            cout << "Towing" << endl;
            towedVehicle = &v;
            return *this;
        }
    };

    struct TrailerCarC : public TrailerVehicleC<4>, public IReversable
    {
        // Implement the IReversable interface
        void setReverse(bool r) override { cout << "Crrrc" << endl; }

        // Override the parent's tow method
        TrailerCarC& tow(const IVehicle& v) override
        {
            return static_cast<TrailerCarC&>(TrailerVehicleC<4>::tow(v));
        }
    };
  















    /*
     * Towing vehicles attempt #4 using the Curiously Recursive Template Pattern (CRTP)
     */

    template <class ConcreteVehicle, int NumWheels>
    struct TrailerVehicleBase : public Vehicle<NumWheels>
    {
        const Vehicle<NumWheels> *     towedVehicle;
        
        ConcreteVehicle& tow(const Vehicle<NumWheels>& c)
        {
            cout << "Towing" << endl;
            towedVehicle = &c;
            return static_cast<ConcreteVehicle&>(*this);
        }
    };
    
    struct TrailerCarD : public TrailerVehicleBase<TrailerCarD, 4>
    {
        void setReverse(bool r) { cout << "Crrrc" << endl; }
    };
  


  
    void testMe();
}
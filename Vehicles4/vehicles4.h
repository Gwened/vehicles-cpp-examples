#pragma once

#include <vector>
#include <array>
#include <iostream>
#include <memory>

#include "vehicles3.h"

using namespace std;
using namespace v1;
using namespace v2;
using namespace v3;

namespace v4
{
    /*
     * Interfaces
     */
    
    struct IComponent
    {};
    
    struct IFlyComponent : public IComponent
    {};
  
    struct IGroundDriveComponent : public IComponent
    {};
    
    struct IMotorComponent : public IComponent
    {};

    struct IReversableMotorComponent : public IMotorComponent
    {
        virtual void reverse(bool r) = 0;
    };

    /*
     * Concrete part classes
     */

    template <int NumW>
    struct WheeledVehicleComponent : public IGroundDriveComponent
    {
        array<v2::Wheel, NumW>  wheels;
    };

    struct WingVehicleComponent : public IFlyComponent
    {
        array<Wing, 2>  wings;
    };

    struct AutomobileEngineComponent : public IReversableMotorComponent
    {
        Engine   engine;

        void reverse(bool r) override { /* ... */ }
    };
    
    struct PropellerComponent : public IMotorComponent
    {
        Engine   engine;
    };

    /*
     * Enity classes
     */
    
    struct VehicleEntity
    {
        vector<unique_ptr<IComponent>> components;
    };
    
    struct Car : public VehicleEntity
    {
        Car()
        {
            components.emplace_back(make_unique<AutomobileEngineComponent>());
            components.emplace_back(make_unique<WheeledVehicleComponent<4>>());
        }
    };

    struct DualEngineAirplane : public VehicleEntity
    {
        DualEngineAirplane()
        {
            components.emplace_back(make_unique<PropellerComponent>());
            components.emplace_back(make_unique<PropellerComponent>());
            components.emplace_back(make_unique<WheeledVehicleComponent<3>>());
        }
    };
   
    struct Glider : public VehicleEntity
    {
        Glider()
        {
            components.emplace_back(make_unique<WheeledVehicleComponent<3>>());
            components.emplace_back(make_unique<WingVehicleComponent>());
        }
    };
 
 
    void testMe();
}
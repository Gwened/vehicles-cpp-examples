#include "vehicles2.h"

namespace v2
{
    int v2::Wheel::nextSerialNumber = 0;

    void testMe()
    {
        FlexibleCar car(4);
        cout << "sizeof(FlexibleCar):" << sizeof(car) << endl;
        cout << "  including wheels container surface: " << sizeof(vector<Wheel>) << endl;

        // UNCOMMENT ME:
        //car.addWheels(16);
        //cout << "sizeof(FlexibleCar):" << sizeof(car) << endl;
    }
}
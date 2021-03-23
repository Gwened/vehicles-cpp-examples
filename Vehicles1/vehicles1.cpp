
#include "vehicles1.h"

namespace v1
{
    int Wheel::nextSerialNumber = 0;

    void testMe()
    {
        cout << "sizeof(pointer): " << sizeof(void*) << " bytes" << endl;
        cout << "sizeof(float): " << sizeof(float) << " bytes" << endl;
        cout << "sizeof(int): " << sizeof(int) << " bytes" << endl;

        Car car;
        cout << "sizeof(Car):" << sizeof(car) << endl;
        cout << "  including wheel array surface: " << sizeof(array<Wheel, 4>) << endl;
        cout << "imaginary 10-wheel array surface: " << sizeof(array<Wheel, 10>) << endl;
    }
}
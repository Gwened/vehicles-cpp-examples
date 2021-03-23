#include "vehicles3.h"

namespace v3
{
    void testMe()
    {
        {
            TrailerCarA a1, a2, a3;
            auto& a = a1.tow(a2.tow(a3));
            a.setReverse(true);
        }
        
        /*
        {
            TrailerCarB b1, b2, b3;
            auto& b = b1.tow(b2.tow(b3));
            b.setReverse(true);
        }

        {
            TrailerCarC c1, c2, c3;
            auto& c = (c1.tow(c2.tow(c3)));
            c.setReverse(true);
        }

        {
            TrailerCarD d1, d2, d3;
            auto& d = d1.tow(d2.tow(d3));
            d.setReverse(true);
        }
        */
    }
}
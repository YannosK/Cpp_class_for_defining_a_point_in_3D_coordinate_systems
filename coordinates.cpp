#include "coordinates.hpp"

Point::Point(double x, double y, double z, char a)
{
    switch (a)
    {
    case 's':
        this->r_s = x;
        this->azimuth_s = y;
        this->zenith = z;
        break;
    case 'c':
        this->r_c = x;
        this->azimuth_c = y;
        this->z_c = z;
        break;
    default:
        this->x = x;
        this->y = y;
        this->z = z;
        break;
    }
}

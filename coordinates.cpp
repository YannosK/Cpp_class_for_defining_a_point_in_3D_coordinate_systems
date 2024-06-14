#include "coordinates.hpp"
#include <cmath>
#include <float.h>

/********************************/
/* private methods              */
/********************************/

void Point::cartesian_to_spherical()
{
    double azim;

    this->r_s = sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));

    if (this->x == 0.)
        azim = atan2(this->y, DBL_MIN);
    else
        azim = atan2(this->y, this->x);
    if (azim < 0)
        this->azimuth_s = azim + 2. * M_PI;

    if (this->z == 0.)
        this->zenith = atan2(sqrt(pow(this->x, 2) + pow(this->y, 2)), DBL_MIN);
    else
        this->zenith = atan2(sqrt(pow(this->x, 2) + pow(this->y, 2)), this->z);
}

void Point::cartesian_to_cylindrical()
{
}

void Point::cylindrical_to_cartesian()
{
}

void Point::cylindrical_to_spherical()
{
}

void Point::spherical_to_cartesian()
{
}

void Point::spherical_to_cylindrical()
{
}

/********************************/
/* constructor                  */
/********************************/

Point::Point(double x, double y, double z, char a)
{
    switch (a)
    {
    case 's':
        this->r_s = x;
        this->azimuth_s = y;
        this->zenith = z;
        spherical_to_cartesian();
        spherical_to_cylindrical();
        break;
    case 'c':
        this->r_c = x;
        this->azimuth_c = y;
        this->z_c = z;
        cylindrical_to_cartesian();
        cylindrical_to_spherical();
        break;
    default:
        this->x = x;
        this->y = y;
        this->z = z;
        cartesian_to_spherical();
        cartesian_to_cylindrical();
        break;
    }
}

/********************************/
/* public methods               */
/********************************/

// by value!!!
double Point::getCartesianX() { return this->x; }

double Point::getCartesianY() { return this->y; }

double Point::getCartesianZ() { return this->z; }

double Point::getSphericalRadial() { return this->r_s; }

double Point::getSphericalAzimuth() { return this->azimuth_s; }

double Point::getSphericalZenith() { return this->zenith; }

double Point::getCylindricalRadial() { return this->r_c; }

double Point::getCylindricalAzimuth() { return this->azimuth_c; }

double Point::getCylindricalZ() { return this->z_c; }

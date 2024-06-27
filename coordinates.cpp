#include "coordinates.hpp"
#include <iostream>
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
    else
        this->azimuth_s = azim;

    // not sure if it needs a check like azimuth
    if (this->z == 0.)
        this->zenith = atan2(sqrt(pow(this->x, 2) + pow(this->y, 2)), DBL_MIN);
    else
        this->zenith = atan2(sqrt(pow(this->x, 2) + pow(this->y, 2)), this->z);
}

void Point::cartesian_to_cylindrical()
{
    double azim;

    this->r_c = sqrt(pow(this->x, 2) + pow(this->y, 2));

    if (this->x == 0.)
        azim = atan2(this->y, DBL_MIN);
    else
        azim = atan2(this->y, this->x);
    if (azim < 0)
        this->azimuth_c = azim + 2. * M_PI;
    else
        this->azimuth_c = azim;

    this->z_c = this->z;
}

void Point::cylindrical_to_cartesian()
{
    this->x = (this->r_c) * cos(this->azimuth_c);

    this->y = (this->r_c) * sin(this->azimuth_c);

    this->z = this->z_c;
}

void Point::cylindrical_to_spherical()
{
    this->r_s = sqrt(pow(this->r_c, 2) + pow(this->z_c, 2));

    this->azimuth_s = this->azimuth_c;

    // not sure if it needs a check like azimuth
    if (this->z_c == 0.)
        this->zenith = atan2(this->r_c, DBL_MIN);
    else
        this->zenith = atan2(this->r_c, this->z_c);
}

void Point::spherical_to_cartesian()
{
    this->x = (this->r_s) * sin(this->zenith) * cos(this->azimuth_s);

    this->y = (this->r_s) * sin(this->zenith) * sin(this->azimuth_s);

    this->z = (this->r_s) * cos(this->zenith);
}

void Point::spherical_to_cylindrical()
{
    this->r_c = (this->r_s) * sin(this->zenith);

    this->azimuth_c = this->azimuth_s;

    this->z_c = (this->r_s) * cos(this->zenith);
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

/*------------------------Getters---------------------------------*/

double Point::getCartesianX() { return this->x; }

double Point::getCartesianY() { return this->y; }

double Point::getCartesianZ() { return this->z; }

double Point::getSphericalRadial() { return this->r_s; }

double Point::getSphericalAzimuth() { return this->azimuth_s; }

double Point::getSphericalZenith() { return this->zenith; }

double Point::getCylindricalRadial() { return this->r_c; }

double Point::getCylindricalAzimuth() { return this->azimuth_c; }

double Point::getCylindricalZ() { return this->z_c; }

/*------------------------Printers--------------------------------*/

/**
 * Prints cartesian coordinates of Point object
 * The form is: [ x , y , z ]
 */
void Point::printCartesian()
{
    std::cout << "[ " << this->x << " , " << this->y << " , " << this->z << " ]" << std::endl;
}

/**
 * Prints cylindrical coordinates of Point object
 * The form is: [ radius , azimuth , z ]
 *
 * radius is on the x-y plane and z is the third dimension
 */
void Point::printCylindrical()
{
    std::cout << "[ " << this->r_c << " , " << this->azimuth_c << " , " << this->z_c << " ]" << std::endl;
}

/**
 * Prints cartesian coordinates of Point object
 * The form is: [ radius , azimuth , zenith ]
 */
void Point::printSpherical()
{
    std::cout << "[ " << this->r_s << " , " << this->azimuth_s << " , " << this->zenith << " ]" << std::endl;
}

// std::ostream Point::printToStreamCartesian()
// {
//     std::ostream stream;
//     stream << "[ " << this->x << " , " << this->y << " , " << this->z << " ]";
//     return stream;
// }

/********************************/
/* operator overloads           */
/********************************/

// Point Point::operator+(Point b)
// {
//     Point a;
// }

double distance_of_points(Point a, Point b)
{
    double x = a.getCartesianX() - b.getCartesianX();
    double y = a.getCartesianY() - b.getCartesianY();
    double z = a.getCartesianZ() - b.getCartesianZ();

    return sqrt(x * x + y * y + z * z);
}
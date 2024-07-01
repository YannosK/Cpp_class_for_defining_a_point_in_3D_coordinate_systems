#include "coordinates.hpp"
#include <iostream>
#include <cmath>
#include <float.h>

/****************************************************************************/
/* CLASS DEFINITIONS                                                        */
/****************************************************************************/

/********************************/
/* static field initialization  */
/********************************/

unsigned int Point::pointsNum = 0;

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
        if (x < 0)
            this->r_s = -x;
        else
            this->r_s = x;

        if (y < 0)
        {
            do
            {
                y = y + 2 * M_PI;
            } while (y < 0);
        }
        else
        {
            if (y > 2 * M_PI)
            {
                do
                {
                    y = y - 2 * M_PI;
                } while (y > 2 * M_PI);
            }
        }
        this->azimuth_s = y;

        if (z < 0)
            this->zenith = 0.;
        else if (z > M_PI)
            this->zenith = M_PI;
        else
            this->zenith = z;

        spherical_to_cartesian();
        spherical_to_cylindrical();
        break;
    case 'c':
        if (x < 0)
            this->r_c = -x;
        else
            this->r_c = x;

        if (y < 0)
        {
            do
            {
                y = y + 2 * M_PI;
            } while (y < 0);
        }
        else
        {
            if (y > 2 * M_PI)
            {
                do
                {
                    y = y - 2 * M_PI;
                } while (y > 2 * M_PI);
            }
        }
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
    (this->pointsNum)++;
}

Point::Point(const Point &pointToCopy)
{
    this->x = pointToCopy.x;
    this->y = pointToCopy.y;
    this->z = pointToCopy.z;
    cartesian_to_cylindrical();
    cartesian_to_spherical();
    (this->pointsNum)++;
}

/********************************/
/* destructor                   */
/********************************/

Point::~Point() { (this->pointsNum)--; }

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

unsigned int Point::getNumberOfPoints() { return Point::pointsNum; }

/*-----------------------Setters------------------------------------*/

void Point::setCartesian(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    cartesian_to_cylindrical();
    cartesian_to_spherical();
}

void Point::setCylindrical(double r_c, double azimuth_c, double z_c)
{
    this->r_c = r_c;

    if (azimuth_c < 0)
    {
        do
        {
            azimuth_c = azimuth_c + 2 * M_PI;
        } while (azimuth_c < 0);
    }
    else
    {
        if (azimuth_c > 2 * M_PI)
        {
            do
            {
                azimuth_c = azimuth_c - 2 * M_PI;
            } while (azimuth_c > 2 * M_PI);
        }
    }
    this->azimuth_c = azimuth_c;

    if (z_c < 0)
        this->z_c = -z_c;
    else
        this->z_c = z_c;

    cylindrical_to_cartesian();
    cylindrical_to_spherical();
}

void Point::setSpherical(double r_s, double azimuth_s, double zenith)
{
    if (r_s < 0)
        this->r_s = -r_s;
    else
        this->r_s = r_s;

    if (azimuth_s < 0)
    {
        do
        {
            azimuth_s = azimuth_s + 2 * M_PI;
        } while (azimuth_s < 0);
    }
    else
    {
        if (azimuth_s > 2 * M_PI)
        {
            do
            {
                azimuth_s = azimuth_s - 2 * M_PI;
            } while (azimuth_s > 2 * M_PI);
        }
    }
    this->azimuth_s = azimuth_s;

    if (zenith < 0)
        this->zenith = 0;
    else if (zenith > M_PI)
        this->zenith = M_PI;
    else
        this->zenith = zenith;

    spherical_to_cartesian();
    spherical_to_cylindrical();
}

/*------------------------Printers--------------------------------*/

void Point::printCartesian()
{
    std::cout << "[ " << this->x << " , " << this->y << " , " << this->z << " ]" << std::endl;
}

void Point::printCylindrical()
{
    std::cout << "[ " << this->r_c << " , " << this->azimuth_c << " , " << this->z_c << " ]" << std::endl;
}

void Point::printSpherical()
{
    std::cout << "[ " << this->r_s << " , " << this->azimuth_s << " , " << this->zenith << " ]" << std::endl;
}

/****************************************************************************/
/* OPERATOR OVERLOADS                                                       */
/****************************************************************************/

std::ostream &operator<<(std::ostream &stream, Point b)
{
    stream << "[ " << b.getCartesianX() << " , " << b.getCartesianY() << " , " << b.getCartesianZ() << " ]";
    return stream;
}

std::istream &operator>>(std::istream &in, Point &b)
{
    double x, y, z;

    std::cout << "\nEnter x : ";
    in >> x;
    std::cout << "Enter y : ";
    in >> y;
    std::cout << "Enter z : ";
    in >> z;
    b.setCartesian(x, y, z);

    return in;
}
/****************************************************************************/
/* FUNCTIONS                                                                */
/****************************************************************************/

double distance_of_points(Point a, Point b)
{
    double x = a.getCartesianX() - b.getCartesianX();
    double y = a.getCartesianY() - b.getCartesianY();
    double z = a.getCartesianZ() - b.getCartesianZ();

    return sqrt(x * x + y * y + z * z);
}
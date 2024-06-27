#ifndef __COORDINATES_HPP
#define __COORDINATES_HPP

#include <iostream>

/****************************************************************************/
/* CLASS DECLARATIONS                                                       */
/****************************************************************************/

class Point
{
private:
    /********************************/
    /* private fields               */
    /********************************/

    // Cartesian coordinates
    double x;
    double y;
    double z;
    // Spherical coordinates
    double r_s;
    double azimuth_s; // in xy pane, from x to y
    double zenith;    // angle from z-axis to r vector
    // Cylindrical coordinates
    double r_c;
    double azimuth_c; // in xy pane, from x to y
    double z_c;

    // number of created point objects
    static unsigned int pointsNum;

    /********************************/
    /* private methods              */
    /********************************/

    void cartesian_to_spherical();
    void cartesian_to_cylindrical();
    void cylindrical_to_cartesian();
    void cylindrical_to_spherical();
    void spherical_to_cartesian();
    void spherical_to_cylindrical();

public:
    /********************************/
    /* constructors                 */
    /********************************/

    /**
     * Default constructor
     * Supports definition of a point either in cartesian, spherical or cylindrical coordinate systems
     * The differentiation happens with argument a, which is a character
     * By default it creates a point with cartesian coordinates (0,0,0)
     *
     * Args:
     * - x (double) : x coordinate in cartesian, radial coordinate in sperical and cylindrical systems
     * - y (double) : y coordinate in cartesian, azimuth coordinate in sperical and cylindrical systems
     * - z (double) : z coordinate in cartesian and cylindrical systems, zenith coordinate in spherical systems
     * - a (char)   : 'o' for cartesian system, 's' for spherical system, 'c' for cylindrical system
     *
     * ATTENTION:
     * - use rads for angles
     * - In spherical coordinates if you add zenith smaller than zero, it is assumed to be zero
     * - In spherical coordinates if you add zenith larger than pi, it is assumed to be pi
     * - In spherical and cylindrical coordinates azimuth is automatically adjusted to be between 0 to 2*pi rads
     * - In sperical coordinates, if a negative radial is inputed, then its corresponding positive value is saved
     * - In cylindrical coordinates, if a negative z is inputed, then its corresponding positive value is saved
     */
    Point(double x = 0., double y = 0., double z = 0., char a = 'o');

    /**
     * Copy constructor
     * Takes as an already existing Point object
     * It then creates a new object, with all the attributes of the inserted one
     */
    Point(const Point &a);

    /********************************/
    /* destructor                   */
    /********************************/

    /**
     * When Point object goes out of range it is called automatically
     * It decreases the number of created objects
     */
    ~Point();

    /********************************/
    /* public methods               */
    /********************************/

    /*-----------------------Getters (all are by value)----------------*/

    double getCartesianX();
    double getCartesianY();
    double getCartesianZ();

    double getSphericalRadial();
    double getSphericalAzimuth();
    double getSphericalZenith();

    double getCylindricalRadial();
    double getCylindricalAzimuth();
    double getCylindricalZ();

    /**
     * Can be called from any created Point object
     * It returns the value of the static variables that counts all the Point objects currently created
     */
    unsigned int getNumberOfPoints();

    /*-----------------------Setters (only way to change coordinates)-*/

    /**
     * Change the coordinates of the Point object using cartesian coordinates
     * The input arguments are x, y, z
     */
    void setCartesian(double x, double y, double z);

    /**
     * Change the coordinates of the Point object using cylindrical coordinates
     * The input arguments are radial, azimuth, z
     *
     * ATTENTION:
     * - use rads for angles
     * - azimuth is automatically adjusted to be between 0 to 2*pi rads
     * - if a negative z_c is inputed, then its corresponding positive value is saved
     */
    void setCylindrical(double r_c, double azimuth_c, double z_c);

    /**
     * Change the coordinates of the Point object using spherical coordinates
     * The input arguments are radial, azimuth, zenith
     *
     * ATTENTION:
     * - use rads for angles
     * - if you add zenith smaller than zero, it is assumed to be zero
     * - if you add zenith larger than pi, it is assumed to be pi
     * - azimuth is automatically adjusted to be between 1 to 2*pi rads
     * - if a negative radial is inputed, then its corresponding positive value is saved
     */
    void setSpherical(double r_s, double azimuth_s, double zenith);

    /*------------------------Printers--------------------------------*/

    void printCartesian();
    void printCylindrical();
    void printSpherical();
};

/****************************************************************************/
/* OPERATOR OVERLOADS                                                       */
/****************************************************************************/

/**
 * Prints to ostream the cartesian representation of the Point object
 * ATTENTION: works only with cartesian coordinates
 */
std::ostream &operator<<(std::ostream &stream, Point b);

/**
 * Inputs from istream values for Point object
 * ATTENTION: works only with cartesian coordinates
 */
std::istream &operator>>(std::istream &in, Point &b);

/****************************************************************************/
/* FUNCTIONS                                                                */
/****************************************************************************/

/**
 * A function that calculates the distance between two point objects
 * Since Point objects are 3D vectors this corresponds to vector subtraction that produces a distance vector
 * This function returns the magnitude of this distance vector
 *
 * Args:
 * - a (Point object type) : starting point
 * - b (Point object type) : ending point
 *
 * Returns:
 * - a double that corresponds to the distance between them
 */
double distance_of_points(Point a, Point b);

#endif
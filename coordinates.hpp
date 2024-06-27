#ifndef __COORDINATES_HPP
#define __COORDINATES_HPP

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
    /* constructor                  */
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
     */
    Point(double x = 0., double y = 0., double z = 0., char a = 'o');

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

    /*------------------------Printers--------------------------------*/

    void printCartesian();
    void printCylindrical();
    void printSpherical();

    // ostream printToStreamCartesian();

    /********************************/
    /* operator overloads           */
    /********************************/

    // Point operator+(Point b);
};

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
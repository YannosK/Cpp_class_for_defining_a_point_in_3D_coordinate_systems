#ifndef __COORDINATES_HPP
#define __COORDINATES_HPP

class Point
{
private:
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
    double azimuth_c;
    double z_c;

public:
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
};

#endif
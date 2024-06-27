#include <iostream>
#include "coordinates.hpp"

using namespace std;

int main(void)
{
    Point p1;                            // Point without initiallisation to check the default constructor
    Point p2 = Point(2, 2, 1);           // Point wihtout spedification of system, should automatically be cartesian
    Point p3 = Point(5, 0.66, 2, 'c');   // Point in cylindrical coordinates
    Point p4 = Point(8, 7.2, 4.12, 's'); // Point in spherical coordinates

    /*********************************************************************************/
    // Using the print methods - called as regular functions (no operation overloads)
    /*********************************************************************************/

    cout << "\nCoordinates of Point p1:" << endl;
    cout << "Cartesian: ";
    p1.printCartesian();
    cout << "Cylindrical: ";
    p1.printCylindrical();
    cout << "Spherical: ";
    p1.printSpherical();

    cout << "\nCoordinates of Point p2:" << endl;
    cout << "Cartesian: ";
    p2.printCartesian();
    cout << "Cylindrical: ";
    p2.printCylindrical();
    cout << "Spherical: ";
    p2.printSpherical();

    cout << "\nCoordinates of Point p3:" << endl;
    cout << "Cartesian: ";
    p3.printCartesian();
    cout << "Cylindrical: ";
    p3.printCylindrical();
    cout << "Spherical: ";
    p3.printSpherical();

    cout << "\nCoordinates of Point p4:" << endl;
    cout << "Cartesian: ";
    p4.printCartesian();
    cout << "Cylindrical: ";
    p4.printCylindrical();
    cout << "Spherical: ";
    p4.printSpherical();

    /*********************************************************************************/
    // Fetching individual coordinates, using the available public methods
    /*********************************************************************************/

    cout << "\nx, radial from spherical and radial from cylindrical coordinates for Point p2:" << endl
         << "x = " << p2.getCartesianX() << endl
         << "radial spherical = " << p2.getSphericalRadial() << endl
         << "radial cylindrical = " << p2.getCylindricalRadial() << endl;

    cout << "\ny and azimuth (both for spherical and cylindrical) coordinatesfor Point p3:" << endl
         << "y = " << p3.getCartesianY() << endl
         << "azimuth spherical = " << p3.getSphericalAzimuth() << endl
         << "azimuth cylindrical = " << p2.getCylindricalAzimuth() << endl;

    return 0;
}
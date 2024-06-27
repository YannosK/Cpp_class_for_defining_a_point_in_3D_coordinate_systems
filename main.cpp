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
          << "azimuth spherical = " << p3.getSphericalAzimuth() << " rads" << endl
          << "azimuth cylindrical = " << p3.getCylindricalAzimuth() << " rads" << endl;

     cout << "\nz (both for cartesian and cylindrical) and zenith coordinatesfor Point p4:" << endl
          << "z cartesian = " << p4.getCartesianZ() << endl
          << "z cylindrical = " << p4.getCylindricalZ() << endl
          << "zenith = " << p4.getSphericalZenith() << " rads" << endl;

     /*********************************************************************************/
     // Testing overloaded operator << and >> operators
     /*********************************************************************************/

     cout << "\nPlease insert new values to p1:";
     cin >> p1;

     cout << endl
          << "Point p1: " << p1 << endl
          << "Point p2: " << p2 << endl
          << "Point p3: " << p3 << endl
          << "Point p4: " << p4 << endl;

     /*********************************************************************************/
     // Setting / changing coordinates, using the available public methods
     /*********************************************************************************/

     p1.setCartesian(3, 0, 2.5);
     cout << "\nChanged p1 = ";
     p1.printCartesian();

     p2.setCartesian(0, 4, 2.5);
     cout << "\nChanged p2 = " << p2 << endl;

     p3.setCylindrical(8.5, 3.14, 10);
     cout << "\nChanged p1 = ";
     p3.printCylindrical();

     p4.setSpherical(32, 2.13, 3.12);
     cout << "\nChanged p1 = ";
     p4.printSpherical();

     /*********************************************************************************/
     // Testing the distance function
     /*********************************************************************************/

     Point r1 = Point(3, 0, 2.5);
     Point r2 = Point(0, 4, 2.5);

     cout << "\nDistance of r1 and r2: " << distance_of_points(r1, r2) << endl;

     return 0;
}
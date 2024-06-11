cmake_minimum_required(VERSION 3.1)

project(Coordinates_Class   VERSION 1.0
                            DESCRIPTION "C++ project for UoA Control & Computing MSc"
                            LANGUAGES CXX)

add_executable(coordinate_systems main.cpp coordinates.cpp coordinates.hpp)
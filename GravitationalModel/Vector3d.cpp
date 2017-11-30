//
//  Vector3d.cpp
//  
//
//  Created by Maxime Moison on 11/29/17.
//

#include "Vector3d.hpp"

Vector3d::Vector3d() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector3d::Vector3d(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Vector3d::operator = (Vector3d const v) {
    x = v.x;
    y = v.y;
    z = v.z;
}

Vector3d Vector3d:: operator + (Vector3d const v) {
    return Vector3d(x+v.x, y+v.y, z+v.z);
}

Vector3d Vector3d::operator * (Vector3d const v) {
    return Vector3d(x*v.x, y*v.y, z*v.z);
}

Vector3d Vector3d:: operator - (Vector3d const v) {
    return Vector3d(x-v.x, y-v.y, z-v.z);
}

Vector3d Vector3d:: operator / (Vector3d const v) {
    return Vector3d(x/v.x, y/v.y, z/v.z);
}

Vector3d Vector3d:: operator + (double const s) {
    return Vector3d(x+s, y+s, z+s);
}

Vector3d Vector3d:: operator * (double const s) {
    return Vector3d(x*s, y*s, z*s);
}

Vector3d Vector3d:: operator - (double const s) {
    return Vector3d(x-s, y-s, z-s);
}

Vector3d Vector3d:: operator / (double const s) {
    return Vector3d(x/s, y/s, z/s);
}

double Vector3d::abs() {
    return pow((pow(x, 2)+pow(y, 2)+pow(z, 2)),0.5);
}

string Vector3d::desc() {
    ostringstream s;
    s << "(x: " << x << ", y: " << y << ", z: " << z << ")";
    return s.str();
}

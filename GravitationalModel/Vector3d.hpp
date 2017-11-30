//
//  Vector3d.hpp
//  
//
//  Created by Maxime Moison on 11/29/17.
//

#ifndef Vector3d_hpp
#define Vector3d_hpp

#include <cmath>
#include <string>
#include <sstream>

using namespace std;

class Vector3d {
public:
    double x;
    double y;
    double z;
    
    Vector3d();
    Vector3d(double x, double y, double z);
    
    void operator = (Vector3d const v);
    
    Vector3d operator + (Vector3d const v);
    Vector3d operator * (Vector3d const v);
    Vector3d operator - (Vector3d const v);
    Vector3d operator / (Vector3d const v);
    
    Vector3d operator + (double const s);
    Vector3d operator * (double const s);
    Vector3d operator - (double const s);
    Vector3d operator / (double const s);
    
    double abs();
    
    string desc();
};

#endif /* Vector3d_hpp */

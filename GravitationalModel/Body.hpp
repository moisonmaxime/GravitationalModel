//
//  Body.hpp
//  
//
//  Created by Maxime Moison on 11/28/17.
//

#ifndef Body_hpp
#define Body_hpp

#include <string>
#include <list>
#include "Vector3d.hpp"

const double G = 6.67e-11;

class Body {
public:
    string name;
    double mass;
    double radius;
    Vector3d position;
    Vector3d velocity;
    
    Body(string name, double mass, double radius, Vector3d position, Vector3d velocity);
    double distanceFrom(Body* other);
    double speed();
    Vector3d gravitationalForce(Body* other);
    Vector3d acceleration(Body* other);
    Vector3d acceleration(list<Body*> others);
    void apply(list<Body*> others, double seconds);
};

#endif /* Body_hpp */

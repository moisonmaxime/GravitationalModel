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

const double G = 6.67e-11;  # Gravitational Constant

class Body {
public:
    string name;        # name of the body
    double mass;        # mass of the body
    double radius;      # radius of the body
    Vector3d position;  # position of the body
    Vector3d velocity;  # velocity of the body
    
    Body(string name, double mass, double radius, Vector3d position, Vector3d velocity);    # Constructor
    double distanceFrom(Body* other);                                                       # Distance form other body
    double speed();                                                                         # Speed of body
    Vector3d gravitationalForce(Body* other);                                               # Gravitational force from other
    Vector3d acceleration(Body* other);                                                     # Acceleration from other body
    Vector3d acceleration(list<Body*> others);                                              # Acceleration from multiple bodies
    void apply(list<Body*> others, double seconds);                                         # Apply the forces to object
};

#endif /* Body_hpp */

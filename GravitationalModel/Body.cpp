//
//  Body.cpp
//  
//
//  Created by Maxime Moison on 11/28/17.
//

#include "Body.hpp"
#include <iostream> // #############

Body::Body(string name, double mass, double radius, Vector3d position, Vector3d velocity) {
    this->name = name;
    this->mass = mass;
    this->radius = radius;
    this->position = position;
    this->velocity = velocity;
}

double Body::distanceFrom(Body* other) {
    Vector3d delta = other->position - position;
    return delta.abs();
}

double Body::speed() {
    return velocity.abs();
}

Vector3d Body::gravitationalForce(Body* other) {
    Vector3d delta = other->position - position;
    Vector3d test = delta * (G * mass * other->mass);
    return delta * (G * mass * other->mass / pow(delta.abs(), 3));
}

Vector3d Body::acceleration(Body* other) {
    return gravitationalForce(other) / mass;
}

Vector3d Body::acceleration(list<Body*> others) {
    list<Body*>::iterator b;
    Vector3d A = Vector3d();
    for (b = others.begin(); b != others.end(); b++) {
        //cout << "[DEBUG] acceleration - " << name << (*b)->name << endl;
        if ((*b)->name != name) {
            A = A + acceleration(*b);
        }
    }
    return A;
}

void Body::apply(list<Body*> others, double seconds) {
    Vector3d A = acceleration(others);
    //cout << "[DEBUG] apply - " << name << " - "<< A.desc() << endl;
    velocity = velocity + A * seconds;
    position = position + velocity * seconds;
}


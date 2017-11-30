//
//  main.cpp
//  
//
//  Created by Maxime Moison on 11/29/17.
//

#include "Universe.hpp"
#include <iostream>
#include <unistd.h>
#include <time.h>

using namespace std;

void *worker_thread(void *arg)
{
    printf("This is worker_thread()\n");
    pthread_exit(NULL);
}

int main() {
    
    Universe u = Universe();
    
    Body* sun = new Body("sun", 1.989e+30, 1, Vector3d(0, 0, 0), Vector3d(0, 0, 0));
    
    Body* mercury = new Body("mercury", 0.33011e+24, 1, Vector3d(4.600e+10, 0, 0), Vector3d(0, 58980, 0));
    
    Body* venus = new Body("venus", 4.8675e+24, 1, Vector3d(1.0748e+11, 0, 0), Vector3d(0, 35260, 0));
    
    Body* earth = new Body("earth", 5.9723e+24, 1, Vector3d(1.4709e+11, 0, 0), Vector3d(0, 30290, 0));
    Body* moon = new Body("moon", 0.07346e+24, 1, Vector3d(1.4709e+11+3.6330e+8, 0, 0), Vector3d(0, 30290+1082, 0));
    
    Body* mars = new Body("mars", 0.64171e+24, 1, Vector3d(2.0662e+11, 0, 0), Vector3d(0, 26500, 0));
    
    Body* jupiter = new Body("jupiter", 1.89819e+27, 1, Vector3d(7.4052e+11, 0, 0), Vector3d(0, 13720, 0));
    
    Body* saturn = new Body("saturn", 5.6834e+26, 1, Vector3d(1.35255e+12, 0, 0), Vector3d(0, 10180, 0));
    
    Body* uranus = new Body("uranus", 8.6813e+25, 1, Vector3d(2.7413e+12, 0, 0), Vector3d(0, 7110, 0));
    
    Body* neptune = new Body("neptune", 1.02413e+26, 1, Vector3d(4.44445e+12, 0, 0), Vector3d(0, 5500, 0));
    
    u.content.push_front(sun);
    u.content.push_front(mercury);
    u.content.push_front(venus);
    u.content.push_front(earth);
    u.content.push_front(moon);
    u.content.push_front(mars);
    u.content.push_front(jupiter);
    u.content.push_front(saturn);
    u.content.push_front(uranus);
    u.content.push_front(neptune);
    
    double seconds = 24*3600;
    double precision = 0.1;
    
    while (true) {
        clock_t t;
        t = clock();
        u.jumpTo(seconds, precision);
        t = clock() - t;
        double seconds = (double)t/CLOCKS_PER_SEC;
        cout << moon->distanceFrom(earth) << " meters" << endl;
        cout << "24h forecast generated in " << seconds << " seconds" << endl;
        usleep(1000);
    }
}

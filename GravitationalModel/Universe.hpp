//
//  Universe.hpp
//  
//
//  Created by Maxime Moison on 11/28/17.
//

#ifndef Universe_hpp
#define Universe_hpp

#include "Body.hpp"
#include <pthread.h>


class Universe {
public:
    list<Body *> content;
    Universe();
//    int going; // Use to keep track of threads in the case of multiThreaded process
    
    void jumpTo(double seconds, double persec);     // generate forecast in *seconds* seconds sampling *persec* per seconds
    void nextFrame(double seconds);                 // generate frame in *seconds* seconds
    
    void threadedJump(double seconds, double persec);   // jumpTo multithreaded - values are incorrect (threads do work)
    static void *jump(void* context);                   // 
    void nextFrame(Body* body, double seconds);         // 
};

struct thread_args {            // Struct to provide arguments to thread worker
    Universe* universe;
    Body* body;
    double seconds;
    double persec;
};

#endif /* Universe_hpp */

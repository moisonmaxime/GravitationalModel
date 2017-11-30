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
    int going;
    
    void jumpTo(double seconds, double persec);
    void nextFrame(double seconds);
    
    void threadedJump(double seconds, double persec);
    static void *jump(void* context);
    void nextFrame(Body* body, double seconds);
};

struct thread_args {
    Universe* universe;
    Body* body;
    double seconds;
    double persec;
};

#endif /* Universe_hpp */

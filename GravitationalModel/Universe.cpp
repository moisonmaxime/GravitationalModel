//
//  Universe.cpp
//  
//
//  Created by Maxime Moison on 11/28/17.
//

#include "Universe.hpp"

Universe::Universe() { /*this->going = 0;*/ }

void Universe::jumpTo(double seconds, double persec) {
    int frames = int(seconds * persec);
    for (int i=0; i<frames; i++)
        nextFrame(1.0 / persec);
}

void Universe::nextFrame(double seconds) {
    list<Body *>::iterator b;
    for (b = content.begin(); b != content.end(); b++) {
        (*b)->apply(content, seconds);
    }
}



//void Universe::threadedJump(double seconds, double persec) {
    list<Body *>::iterator b;
    pthread_t threads[content.size()];
    int ret[content.size()];
    int i = 0;
    
    for (b = content.begin(); b != content.end(); b++) {
        // create and run threads
        
        struct thread_args args;
        args.body = *b;
        args.seconds = seconds;
        args.persec = persec;
        args.universe = this;
        
        ret[i] = pthread_create(&threads[i], NULL, &Universe::jump, &args);
        if (ret[i] != 0) {
            perror("pthread_create failed\n");
            exit(EXIT_FAILURE);
        }
        i++;
    }
    
    for (i=0; i<content.size(); i++) {
        ret[i] = pthread_join(threads[i], NULL);
        if (ret[i] != 0) {
            perror("pthread_join failed\n");
            exit(EXIT_FAILURE);
        }
    }
}

//void *Universe::jump(void* context) {
    struct thread_args *args = (struct thread_args *) context;
    int frames = int(args->seconds * args->persec);
    for (int i=0; i<frames; i++) {
        args->universe->going ++;
        args->universe->nextFrame(args->body, 1.0 / args->persec);
        args->universe->going --;
        while (args->universe->going !=0) { }
    }
    pthread_exit(NULL);
    return NULL;
}

//void Universe::nextFrame(Body* body, double seconds) {
    body->apply(content, seconds);
}

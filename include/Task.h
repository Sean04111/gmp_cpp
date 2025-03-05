//
// Created by Sean on 3/5/25.
//
#ifndef TASK_H
#define TASK_H
#include <iostream>



class Task {
public:
    void operator()(int count) const {
        for (int i = 0; i < count; i++) {
            std::cout << "hello from thread (function object)! \n";
        }
    }

    Task() {}
};

#endif //TASK_H

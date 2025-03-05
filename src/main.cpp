//
// Created by Sean on 3/5/25.
//

#include <iostream>
#include <thread>

#include "../include/Task.h"


std::thread thread_work() {
    std::cout << "thread working" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "thread work finished" << std:: endl;
}

int main(){
    std::thread t(thread_work());
    t.join();
    return 0;
}

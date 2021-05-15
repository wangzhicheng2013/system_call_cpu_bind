#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <thread>
#include "cpu_utility.hpp"
void exhaust_cpu() {
    std::cout << system("./exhaust_cpu") << std::endl;
}
int main() {
    G_CPU_UTILITY.bind_cpu(1);
    std::thread th0(exhaust_cpu);
    std::thread th1(exhaust_cpu);
    if (th0.joinable()) {
        th0.join();
    }
    if (th1.joinable()) {
        th1.join();
    }

    return 0;
}
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <thread>
#include "cpu_utility.hpp"
void exhaust_cpu() {
    std::cout << system("./exhaust_cpu") << std::endl;
}
int main() {
    //int cpu_no = 21;
    //G_CPU_UTILITY.bind_cpu(cpu_no);
    std::cout << G_CPU_UTILITY.bind_all_cpus() << std::endl;
    int pid = -1;
    if (0 == (pid = fork())) {
        int cpu_num = G_CPU_UTILITY.get_cpu_num();
        for (int cpu_no = 0;cpu_no < cpu_num;cpu_no++) {
            if (G_CPU_UTILITY.run_in_cpu(cpu_no)) {
                std::cout << "child process run in " << cpu_no << std::endl;
            }
        }
        sleep(1);
        exhaust_cpu();
    }
    int cpu_num = G_CPU_UTILITY.get_cpu_num();
    for (int cpu_no = 0;cpu_no < cpu_num;cpu_no++) {
        if (G_CPU_UTILITY.run_in_cpu(cpu_no)) {
            std::cout << "child process run in " << cpu_no << std::endl;
        }
    }
    sleep(1);

    return 0;
}
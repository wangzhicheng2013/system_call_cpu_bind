#include <unistd.h>
#include <iostream>
// exhaust 70% cpu
static const int SLEEP_TIME_FOR_CPU_EXHAUST_PERCENT_70 = 1000;
int main() {
    while (true) {
        long sum = 0;
        for (int i = 0;i < 1000000;i++) {
            sum += i;
        }
        usleep(SLEEP_TIME_FOR_CPU_EXHAUST_PERCENT_70);
    }
}
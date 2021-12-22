#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main() {
    time_t seconds1;
    struct timeval seconds2;
    struct timespec seconds3;
    clock_t start, result;

    start = clock();
    seconds1 = time(&seconds1);
    result = clock() - start;
    printf("Absolute time: %ld\n", seconds1);
    printf("time of time(): %ld ms\n", result);

    start = clock();
    gettimeofday(&seconds2, NULL);
    result = clock() - start;
    printf("Absolute time: %ld\n", seconds2.tv_sec);
    printf("time of gettimeofday(): %ld ms\n", result);

    start = clock();
    clock_gettime(CLOCK_REALTIME, &seconds3);
    result = clock() - start;
    printf("Absolute time: %ld\n", seconds3.tv_sec);
    printf("time of clock_gettime(): %ld ms\n", result);
    return 0;
}

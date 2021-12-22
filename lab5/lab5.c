#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <math.h>

long double avg(long double *a) {
    long double res = 0.0;
    for (int i = 0; i < 65; ++i) {
        res += a[i];
    }
    res = res / 65;
    return res;
}

int main() {
    clock_t start, end;
    long double time;
    int x;
    long double tdf[65];
    for (x = 0; x <= 64; ++x) {
        start = clock();
        (int *) malloc(pow(2, x));
        end = clock();
        time = ((long double) (end - start)) / (CLOCKS_PER_SEC / 1000);
        printf("Time of malloc() of 2 ^ x (in milliseconds): %Lf, iteration: %d\n", time, x);
        tdf[x] = time;
    }
    printf("Time of malloc() (in average): %Lf\n", avg(tdf));
    for (x = 0; x <= 64; ++x) {
        start = clock();
        (int *) malloc(pow(2, (x + 1)));
        end = clock();
        time = ((long double) (end - start)) / (CLOCKS_PER_SEC / 1000);
        printf("Time of malloc() of 2 ^ (x + 1) (in milliseconds): %Lf, iteration: %d\n", time, x);
        tdf[x] = time;
    }
    printf("Time of malloc() (in average): %Lf\n", avg(tdf));
    for (x = 0; x <= 64; ++x) {
        start = clock();
        (int *) calloc(pow(2, x), sizeof(int));
        end = clock();
        time = ((long double) (end - start)) / (CLOCKS_PER_SEC / 1000);
        printf("Time of calloc() of 2 ^ x (in milliseconds): %Lf, iteration: %d\n", time, x);
        tdf[x] = time;
    }
    printf("Time of calloc() (in average): %Lf\n", avg(tdf));
    for (x = 0; x <= 64; ++x) {
        start = clock();
        (int *) calloc(pow(2, (x + 1)), sizeof(int));
        end = clock();
        time = ((long double) (end - start)) / (CLOCKS_PER_SEC / 1000);
        printf("Time of calloc() of 2 ^ (x + 1) (in milliseconds): %Lf, iteration: %d\n", time, x);
        tdf[x] = time;
    }
    printf("Time of calloc() (in average): %Lf\n", avg(tdf));
    for (x = 0; x <= 64; ++x) {
        start = clock();
        (int *) alloca(sizeof(int) * (pow(2, x)));
        end = clock();
        time = ((long double) (end - start)) / (CLOCKS_PER_SEC / 1000);
        printf("Time of alloca() of 2 ^ x (in milliseconds): %Lf, iteration: %d\n", time, x);
        tdf[x] = time;
    }
    printf("Time of alloca() (in average): %Lf\n", avg(tdf));

    for (x = 0; x <= 64; ++x) {
        start = clock();
        (int *) alloca(sizeof(int) * (pow(2, (x + 1))));
        end = clock();
        time = ((long double) (end - start)) / (CLOCKS_PER_SEC / 1000);
        printf("Time of alloca() of 2 ^ (x + 1) (in milliseconds): %Lf, iteration: %d\n", time, x);
        tdf[x] = time;
    }
    printf("Time of alloca() (in average): %Lf\n", avg(tdf));
    return 0;
}

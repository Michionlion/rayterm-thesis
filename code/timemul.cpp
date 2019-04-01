#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: rtime <N> <WARMUP>\n");
        exit(1);
    }
    int n      = stoi(argv[1]);
    int warmup = stoi(argv[2]);

    steady_clock::time_point begin, end;
    int64_t times[n + warmup];

    for (int i = 0; i < n + warmup; i++) {
        if (i >= warmup) {
            printf("Start run %d\n", i);
        }
        begin   = steady_clock::now();
        float y = 1251.612 * 212.541;
        end     = steady_clock::now();
        if (i > warmup - 1) {
            printf("End run %d, ", i);
        }

        times[i] = duration_cast<std::chrono::nanoseconds>(end - begin).count();
        if (i >= warmup) {
            printf("time: %ldns\n", times[i]);
        }
    }

    int64_t average_time = 0;
    for (int i = warmup; i < n + warmup; i++) {
        average_time += times[i];
    }
    average_time /= n;

    printf("\nSUMMARY\n\nMultiplied %d floats in %ldns on average\n", n, average_time);
    exit(0);
}

#include <iostream>
#include <omp.h>
using namespace std;

int seats = 5;
omp_lock_t lock;

int main() {
    int passengers = 10;

    omp_init_lock(&lock);

    double start = omp_get_wtime();

#pragma omp parallel for
    for (int i = 1; i <= passengers; i++) {

        omp_set_lock(&lock);

        if (seats > 0) {
            cout << "Passenger " << i << " booked. ";
            seats--;
            cout << "Remaining: " << seats << endl;
        } else {
            cout << "Passenger " << i << " failed\n";
        }

        omp_unset_lock(&lock);
    }

    double end = omp_get_wtime();
    cout << "Parallel (Lock) Time: " << (end - start) << " sec\n";

    omp_destroy_lock(&lock);
}
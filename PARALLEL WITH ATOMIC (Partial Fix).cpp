#include <iostream>
#include <omp.h>
using namespace std;

int seats = 5;

int main() {
    int passengers = 10;

    double start = omp_get_wtime();

#pragma omp parallel for
    for (int i = 1; i <= passengers; i++) {

        if (seats > 0) {

#pragma omp atomic
            seats--;

            cout << "Passenger " << i
                 << " booked. Remaining: "
                 << seats << endl;
        } else {
            cout << "Passenger " << i << " failed\n";
        }
    }

    double end = omp_get_wtime();
    cout << "Parallel (Atomic) Time: " << (end - start) << " sec\n";
}
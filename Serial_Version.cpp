#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    int seats = 5;
    int passengers = 10;

    double start = omp_get_wtime();

    for (int i = 1; i <= passengers; i++) {
        if (seats > 0) {
            cout << "Passenger " << i << " booked. ";
            seats--;
            cout << "Remaining: " << seats << endl;
        } else {
            cout << "Passenger " << i << " failed\n";
        }
    }

    double end = omp_get_wtime();
    cout << "Serial Time: " << (end - start) << " sec\n";
}
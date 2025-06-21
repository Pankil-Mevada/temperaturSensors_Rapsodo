#include "TemperatureSensor.hpp"
#include <cstdlib>
#include <ctime>


int main() {
    const size_t N = 5;  
    TemperatureSensor process(N);

    srand(static_cast<unsigned int>(time(0)));

    for (size_t t = 0; t < 100; ++t) {
        double newReading = static_cast<double>(rand()) / RAND_MAX * 100.0;
        process.addReading(newReading);

        if (t >= N - 1) {  
            double fusion1 = process.fusionFunction1();
            double fusion2 = process.fusionFunction2();
            cout << "Fusion 1: " << fusion1 << " & Fusion 2: " << fusion2 << endl;
        }
    }

    return 0;
}
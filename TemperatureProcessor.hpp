#include <iostream>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class TemperatureSensor {
private:
    queue<double> window;
    size_t maxSize;
    double logProductSum;

public:
    TemperatureSensor(size_t N) : maxSize(N), logProductSum(0.0) {}

    void addReading(double value) {
        if (window.size() == maxSize) {
            double old = window.front();
            window.pop();
            if (old > 0.0) logProductSum -= log(old);
        }
        window.push(value);
        if (value > 0.0) logProductSum += log(value);
    }

    double fusionFunction1() const {
        if (window.empty()) return 0.0;
        return exp(logProductSum / window.size());
    }

    double fusionFunction2() const {
        if (window.empty()) return 0.0;

        double totalProduct = 1.0;
        int zeroCount = 0;

   
        queue<double> temp = window;
        while (!temp.empty()) {
            double v = temp.front();
            temp.pop();

            if (v == 0.0) {
                zeroCount++;
            } else {
                totalProduct *= v;
            }
        }

        if (zeroCount > 1) return 0.0;

        double sum = 0.0;

        temp = window;
        while (!temp.empty()) {
            double v = temp.front();
            temp.pop();

            if (v == 0.0 || zeroCount == 1) {
                sum += 0.0;
            } else {
                sum += totalProduct / v;
            }
        }

        return sqrt(sum / window.size());
    }
};


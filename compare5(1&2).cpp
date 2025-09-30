#include <iostream>
#include <ctime>
using namespace std;
long long naivePower(long long b, long long n) {
    long long result = 1;
    for (long long i = 1; i <= n; i++) {
        result = result * b;
    }
    return result;
}
long long fastPower(long long b, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long h = fastPower(b, n/2);
        return h * h;
    } else {
        return b * fastPower(b, n-1);
    }
}
int main() {
    long long base, power;
    cout << "Enter base: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> power;

    long long result1, result2;
    int repetitions = 100000;
    // Measure time for Naive
    clock_t start1 = clock();
    for(int i = 0; i < repetitions; i++)
        result1 = naivePower(base, power);
    clock_t end1 = clock();
    double time_naive = double(end1 - start1) / CLOCKS_PER_SEC;
    // Measure time for Fast
    clock_t start2 = clock();
    for(int i = 0; i < repetitions; i++)
        result2 = fastPower(base, power);
    clock_t end2 = clock();
    double time_fast = double(end2 - start2) / CLOCKS_PER_SEC;
    cout << "Results\n";
    cout << "Naive Result = " << result1 << endl;
    cout << "Fast Result  = " << result2 << endl;
    cout << "\n Execution Time (for " << repetitions << " runs)\n";
    cout << "Naive Method: " << time_naive << " seconds\n";
    cout << "Fast Method : " << time_fast << " seconds\n";
    return 0;
}


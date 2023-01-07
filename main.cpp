#include <algorithm>
#include <iostream>
#include <iomanip>
#include <chrono>
#include "sieve_of_eratosthenes.cpp"
using namespace std;

const int NUM_ITERATIONS = 10;

int main()
{
    std::chrono::duration<double> total_time(0.0);
    for(int i = 0;i<NUM_ITERATIONS;i++) {
        std::chrono::time_point<std::chrono::system_clock> start, end;

        start = std::chrono::system_clock::now();
        vector<bool> odd_numbers(1000);
        int n = 3;
        std::generate(odd_numbers.begin(), odd_numbers.end(), [&n](){return n+=2;});
        sift2(odd_numbers.begin(), 1000);
        end = std::chrono::system_clock::now();

        std::chrono::duration<double> elapsed_seconds = end - start;
        total_time += elapsed_seconds;
        cout << std::fixed;
        cout << std::setprecision(10);

        cout <<"#"<< i <<" Elapsed time: " << elapsed_seconds.count() << "\n";
    }
    cout << "Average Time: " << total_time.count()/NUM_ITERATIONS << "\n";

    return EXIT_SUCCESS;
}
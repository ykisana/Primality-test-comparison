// isPrime is function from millerRabin.h
// solovoyTest is from solovoyStrassen.h

#include <iostream>
#include <chrono> // for calculating time
#include <utility>
#include "millerRabin.h"
#include "solovayStrassen.h"
#define LL long long

using namespace std;
using namespace std::chrono; // for time


// caculates and outputs average time of primality test
// uses start and end of range, along with k value
void averageMiller(LL start, LL end, LL k){
    long double total = 0;
    for (LL i = start; i <= end; i++){
        auto t1 = high_resolution_clock::now();
        isPrime(i,k);
        auto t2 = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(t2 - t1);
        total += duration.count();
    }
    cout << "Average Miller Rabin Time(microseconds): " << total/(end-start+1) << '\n';

}
void averageSolovoy(LL start, LL end, LL k){
    long double total = 0;
    for (LL i = start; i <= end; i++){
        auto t1 = high_resolution_clock::now();
        solovoyTest(i,k);
        auto t2 = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(t2 - t1);
        total += duration.count();
    }
    cout << "Average Solovay-Strassen Time(microseconds): " << total/(end-start+1) << '\n' << '\n';
}

//main function is just formatting output and calling of functions
int main(){
    LL start, end, k;
    // k = 1 tests
    k = 1;
    cout << "---- k = "<<k<<"----\n";
    // small number test (range 100 - 10,000)
    start = 100;
    end = 10000;
    cout << "Range ["<<start<<"," <<end<<"]\n";
    averageMiller(start,end,k);
    averageSolovoy(start,end,k);

    // larger number test (range 100000000 - 200000000)
    start = 100000000;
    end = 200000000;
    cout << "Range ["<<start<<"," <<end<<"]\n";
    averageMiller(start,end,k);
    averageSolovoy(start,end,k);

    // k = 4 tests
    k = 4;
    cout << "---- k = "<<k<<"----\n";
    // larger number test (range 100000000 - 200000000)
    start = 100000000;
    end = 200000000;
    cout << "Range ["<<start<<"," <<end<<"]\n";
    averageMiller(start,end+1,k);
    averageSolovoy(start,end+1,k);


    return 0;

}
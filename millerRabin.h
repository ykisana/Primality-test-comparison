// Miller-Rabin Primality test
// this runs in O(klog^3n) time
// long long used to account for large numbers
// modeled from Geeks for Geeks:
// https://www.geeksforgeeks.org/primality-test-set-3-miller-rabin/

#include <stdlib.h>
#include <math.h>
#define LL long long
#pragma once


using namespace std;
bool millerTest(LL n, LL d);
LL fast_exp(LL b, LL n);
LL power(LL x, unsigned LL y, LL p);




// returns (x ^ y) % p
LL power(LL x, LL y, LL p){
    LL out = 1;
    x = x % p;
    while (y > 0){
        if (y & 1)
            out = (out*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return out;
}



bool isPrime(LL n, LL k){
    // n is the number you are checking
    // k is the number of rounds of testing

    //check base cases and if n is even
    if (n <= 1 || n == 4){
        return false;
    }
    if(n <= 3){
        return true;
    }
    if (n % 2 == 0){
        return false;
    }
    // calculate d, where n - 1 = d * 2^2
    LL d = n - 1;
    while (d%2 == 0){
        d /= 2;
    }
    // call millerTest k times
    // if it fails  even  once  out of k times , return  false , else  true
    // it is clear , higher k -> higher  accuracy
    for(LL i = 0; i < k; i++){
        if (!millerTest(n,d)){
            return false;
        }
    }
    return true;
}

bool millerTest(LL n, LL d){
    // generate random number in range [2, n-2]
    LL a = rand() % (n-4) + 2;
    // use the random number to create x
    // x is (a ^ d) % n;
    LL x = power(a,d,n);


    if(x == 1 || x == n -1){
        return true;
    }
    // checks if composite or not
    while (d != n -1){
        x = x*x % n;
        d *= 2;
        if (x == 1){
            return false;
        }
        if (x == n-1){
            return true;
        }
    }
    return false;


}
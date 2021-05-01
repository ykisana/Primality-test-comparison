// Miller-Rabin Primality test
// this runs in O(klog^3n) time
// long long used to account for large numbers


#include <stdlib.h>
#include <math.h>
#define LL long long
#pragma once


using namespace std;
bool millerTest(LL n, LL d);
LL fast_exp(LL b, LL n);


//from UAlberta Competitive Programming Club Repo
LL fast_exp(LL b, LL n){
    LL res = 1, x = b, p;

    for(p = n; p; p >>= 1, x *= x)
        if(p & 1) res *= x;

    return res;
}



bool isPrime(LL n, LL k){
    // n is the number you are checking
    // k is the number of rounds of testing

    //check base cases and if n is even
    if (n == 1 || n == 2 || n == 3){
        return true;
    }
    if (n % 2 == 0){
        return false;
    }
    // calculate d, where n - 1 = d * 2^2
    LL d = n - 1;
    while (d%2 == 0){
        d = d/2;
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
    LL a = rand() % (n-3) + 2;
    // uue the random number to create x
    LL x = fast_exp(a,d) % n;

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
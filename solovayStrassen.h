// Solovay-Strassen Primality test
// this runs in O(klog^3n) time
// long long used to account for large numbers
// modeled from Geeks for Geeks:
// https://www.geeksforgeeks.org/primality-test-set-4-solovay-strassen/

#include <algorithm>
#include <stdlib.h>
#define LL long long
#pragma once

LL modulo(LL b, LL e, LL m);
LL calcJacobian(LL a, LL n);

// for binary exponentiation
LL modulo(LL b, LL e, LL m){
    LL x = 1;
    LL y = b;
    while(e > 0){
        if(e % 2 == 1){
            x = (x*y) % m;
        }
        y = (y*y) % m;
        e /= 2;
    }
    return x % m;
}

// function to calculate jacobian
LL calcJacobian(LL a, LL n){
    if(a == 0){
        return 0;
    }
    LL answer = 1;
    if(a < 0){
        a = -a;
        if(n % 4 == 3){
            answer = -answer;
        }
    }
    if(a == 1) return answer;
    while (a != 0){
        if(a < 0){
            a = -a;
            if(n%4 == 3){
                answer = -answer;
            }
        }
        while (a%2 == 0){
            a /= 2;
            if(n % 8 == 3 || n % 8 == 5){
                answer = -answer;
            }
        }
        swap(a,n);
        if (a % 4 == 3 && n % 4 == 3){
            answer = -answer;
        }
        a = a % n;
        if(a > n/2){
            a = a-n;
        }
    }
    if(n == 1){
        return answer;
    }
    return 0;

}

bool solovoyTest(LL n, LL k){
    // base cases
    if (n == 1 || n == 2){
        return true;
    }
    if (n < 2) return false;
    if (n != 2 && n % 2 == 0) return false;

    // iterate k times, check if probable prime
    for(LL i = 0; i < k; i++){
        LL a = rand() % (n - 1) +1;
        // jacobian and modulo function above used
        LL jac = (calcJacobian(a,n) + n) % n;
        LL mod = modulo(a, (n-1)/2, n);

        // return false if composite in any iteration of k
        if (jac == 0 || mod != jac) return false;
    }
    // passed loop, it is probably prime
    return true;
}

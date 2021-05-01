// Solovay-Strassen Primality test
// this runs in O(klog^3n) time
// long long used to account for large numbers
// modeled from Geeks for Geeks:
// https://www.geeksforgeeks.org/primality-test-set-4-solovay-strassen/

#include <algorithm>
#include <stdlib.h>
#define LL long long
#pragma once

int modulo(int b, int e, int m);
int calcJacobian(int a, int n);

// for binary exponentiation
int modulo(int b, int e, int m){
    int x = 1;
    int y = b;
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
int calcJacobian(int a, int n){
    if(a == 0){
        return 0;
    }
    int answer = 1;
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

bool solovoyTest(int n, int k){
    // base cases
    if (n == 1 || n == 2){
        return true;
    }
    if (n < 2) return false;
    if (n != 2 && n % 2 == 0) return false;

    // iterate k times, check if probable prime
    for(int i = 0; i < k; i++){
        int a = rand() % (n - 1) +1;
        int jac = (calcJacobian(a,n) + n) % n;
        int mod = modulo(a, (n-1)/2, n);

        if (jac == 0 || mod != jac) return false;
    }
    return true;
}

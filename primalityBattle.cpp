#include <iostream>
#include "millerRabin.h"
#include "solovayStrassen.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    cout << isPrime(n,1);
    cout << solovoyTest(n,1);
}
//outputs the next probable prime using Miller-Rabin

#include <iostream>
#include "millerRabin.h"
#define LL long long

int main(){
    LL start;
    LL k;
    cout << "Please enter the number you want to find the next prime for: ";
    cin >> start;
    cout << "\nPlease enter accuracy (how many times to check each value)";
    cin >> k;
    cout << "\nCalculating next prime...\n";
    start++;
    while (true){
        if (isPrime(start,k)){
            break;
        }
        start++;

    }
    cout << "The next probable prime is: " << start << '\n';
    return 0;

}

/*
 * Primality Test
 */

/* 
 * File:   main.cpp
 * Author: Narish Singh
 *
 * Created on May 22, 2020, 5:57 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

/**
 * test if number is prime or not
 * 
 * @param n {int} user's inputted number
 * @return {bool} true is prime, false otherwise
 */
bool is_prime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main(int argc, char** argv) {
    bool calculating = true;
    int n;

    cout << "===Prime Number Test===" << endl;
    while (calculating) {
        cout << "Enter an integer (0 or 1 to exit): ";
        cin>>n;

        if (n == 0 || n == 1) {
            calculating = false;
        } else if (is_prime(n)) {
            cout << n << " is a prime number!!!" << endl;
        } else {
            cout << n << " is not a prime number..." << endl;
        }
    }

    return 0;
}


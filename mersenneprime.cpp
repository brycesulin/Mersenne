/*
 * File: mersenneprime.cpp
 * Author: Bryce Sulin
 *
 * This file finds all Mersenne primes less than the input integer
 */
#include <iostream>

using namespace std;

// Find all prime numbers less than n.
void smallerPrimeNumbers(int n, bool prime[])
{
    for (int i=0; i<=n; i++)
        prime[i] = true;

    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
}

// Function to generate Mersenne primes less than or equal to n
void mersennePrimes(int n)
{
    // Create a boolean array
    bool prime[n+1];

    // Get prime numbers
    smallerPrimeNumbers(n,prime);

    // Get all numbers of the form 2^k - 1
    // and smaller than or equal to n.
    for (int k=2; ((1<<k)-1) <= n; k++)
    {
        long long num = (1<<k) - 1;

        // Check if number is prime and is one less then the power of 2
        if (prime[num])
            cout << num << " ";
    }
    cout << endl;
}

int main()
{
    int n = 31;
    cout << "Mersenne prime numbers smaller "
         << "than or equal to " << n << endl;
    mersennePrimes(n);
    return 0;
}
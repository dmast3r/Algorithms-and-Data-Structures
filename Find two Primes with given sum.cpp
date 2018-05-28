/* Given an even number > 2 find two primes such that sum of these two primes equal to the number. If there are many such primals
then print the first one.
--- Solution ---
The idea is to find all the prime numbers in the range 2 ... n - 2 for a given number n. This is done via Sieve of Eratosthenes.
Now linearly search starting from 2 all the numbers in the range 2...n and if for some number i, if both i as well as n - i are
primes then print them. According to Golbach's Conjecture atleast one such pair will always occur for any even n > 2.
*/

#include <bits/stdc++.h>
using namespace std;

// find all the primes in a given range using sieve of eratosthenes
void buildSieve(bool sieve[], int range) {
    for(int i = 2; i * i <= range; ++i) {
        if(sieve[i] == true) {
            for(int j = i * 2; j <= range; j = j + i)
                sieve[j] = false;
        }
    }
}

// solve for each test case
void solve() {
    int n;
    cin >> n;
    bool sieve[n-1]; // create an array(the sieve) of size n - 1(we only need n - 2 elems but because indexing is 0 based)
    memset(sieve, true, sizeof sieve);

    buildSieve(sieve, n-2);
    for(int i = 2; i < n - 1; ++i) {
        if(sieve[i] and sieve[n-i]) {
            cout << i << " " << n - i << endl;
            break;
        }
    }
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}

#include <bits/stdc++.h>
using namespace std;

bool isPerfect(int n) {
    long int sqrt_n = int(sqrt(n));
    return sqrt_n * sqrt_n == n;
}

int getTotalFactors(int n) {
    int total = 0;
    for(int i = 1; i * i <= n; ++i) {
        if(n % i == 0)
            ++total;
    }
    return 2 * total - isPerfect(n);
}

void solve() {
    int n, k, total_factors, total_covered = 0;
    cin >> n >> k;
    total_factors = getTotalFactors(n);

    for(int i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ++total_covered;
            if(total_covered == k) {
                cout << i << endl;
                break;
            }
            else if(total_factors + 1 - total_covered == k) {
                cout << n / i << endl;
                break;
            }
        }
    }
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}

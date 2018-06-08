#include<bits/stdc++.h>
using namespace std;

// find x ^ y mod M
long long int LargePowerMod(int x, int y, long long int M) {
    if (y == 0)
        return 1;

    long long int temp = LargePowerMod(x, y / 2, M);
    if (y % 2 == 0)
        return (temp % M * temp % M) % M;
    return (temp % M * temp % M * x % M) % M;
}

void solve() {
    int x, y, k;
    long long int M, last_digits, last_digits_one_less, num_digits, res;

    cin >> x >> y >> k;
    M = (long long int) pow(10, k);

    last_digits = LargePowerMod(x, y, M);
    if(k > 1) {
        M = (long long int) pow(10, k-1);
        last_digits_one_less = LargePowerMod(x, y, M);

        if(last_digits_one_less == last_digits) {
            cout << 0 << endl;
            return;
        }
    }

    num_digits = (long long int)(log10(last_digits) + 1);
    res = last_digits / (long long int)((pow(10, num_digits - 1)));

    cout << res << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}

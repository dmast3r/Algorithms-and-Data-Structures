/*
 *  Finding Binomial Coefficient(nCr). It can be done efficiently with Dynamic Programming. As it follows the recurrence relation nCr = (n-1)Cr + (n-1)C(r-1) which has overlapping subproblem and optimal substructure property.
 *
 * We do not need a 2-d array and 1-d will suffice because for caluclating iCr for some only (i-1)C(0..r) need to be known.
 * We can also run the second loop only from min(i, k) because if k > i all then iC(i+1, ..., k) = 0
 */


#include<bits/stdc++.h>
using namespace std;

int binomialCoeff(int n, int k) {
    int C[k+1] = {0};
    C[0] = 1;

    for(int i = 1; i <= n; ++i)  {
        for(int j = min(i, k); j >= 0; --j)
            C[j] = C[j] + C[j-1];
    }
    return C[k];
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << binomialCoeff(n, k);
}

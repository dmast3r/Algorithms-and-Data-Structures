/*
	Given an array a, return the lexiographically smallest array ar, that follows the pattern a[0] >= a[1] <= a[2] >= a[3] <= a[4]....

	Solution : At odd places assign the second-smallest unassigned element and even places assign the smallest unassigned element so far.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int ar[n], war[n];

    for(auto &i : ar)
        cin >> i;
    sort(ar, ar + n);

    if(n == 1) {
        cout << ar[0] << endl;
        return;
    }

    int hare = 1, tortoise = 0, pos = 0, covered = 0;
    while (covered != n) {
        if(hare < n) {
            war[pos++] = ar[hare];
            hare += 2;
            ++covered;
        }

        if(tortoise < n) {
            war[pos++] = ar[tortoise];
            tortoise += 2;
            ++covered;
        }
    }

    for(auto i : war)
        cout << i << " ";
    cout << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}

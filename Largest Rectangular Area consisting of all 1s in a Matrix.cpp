#include <bits/stdc++.h>
using namespace std;

int getLargestArea(int n, int ar[]) {
    int res = INT_MIN;
    stack<int> st;

    for(int i = 0; i < n; ++i) {
        while(!st.empty() and ar[st.top()] > ar[i]) {
            int top = st.top(), elems, area;
            st.pop();

            elems = (st.empty() ? i : i - st.top() - 1);
            area = elems * ar[top];
            res = max(res, area);
        }
        st.push(i);
    }

    while(!st.empty()) {
        int top = st.top(), elems, area;
        st.pop();

        elems = (st.empty() ? n : n - st.top() - 1);
        area = elems * ar[top];
        res = max(res, area);
    }

    return res;
}

void solve() {
    int m, n, res = INT_MIN;
    cin >> m >> n;
    int mat[m][n];

    for(auto &i : mat) {
        for(auto &j : i)
            cin >> j;
    }

    for(int i = 0; i < m; ++i) {
        int dp[n];
        for(int j = 0; j < n; ++j) {
            if(i != 0 and mat[i][j] == 1)
                mat[i][j] += mat[i-1][j];
            dp[j] = mat[i][j];
        }

        res = max(res, getLargestArea(n, dp));
    }

    cout << res << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}

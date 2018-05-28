#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, res = INT_MIN;
    cin >> n;
    int ar[n];
    stack<int> st;

    for(int i = 0; i < n; ++i) {
        cin >> ar[i];

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

    cout << res << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
    return 0;
}

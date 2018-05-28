#include<bits/stdc++.h>
using namespace std;

int getPosition(const char &c) {
    return c - 'a';
}

void solve() {
    int n;
    list<char> ls;
    bool mp[26] = {false};
    cin >> n;

    while(n--) {
        char c;
        cin >> c;

        if(mp[getPosition(c)])
            ls.remove(c);
        else {
            ls.push_back(c);
            mp[getPosition(c)] = true;
        }

        if(ls.empty())
            cout << -1 << " ";
        else
            cout << ls.front() << " ";
    }

    cout << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
    return 0;
}

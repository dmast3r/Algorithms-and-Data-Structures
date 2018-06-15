#include <bits/stdc++.h>
using namespace std;

string preProcess(string str) {
    string res_str(2*str.length(), '#');
    for(int i = 0; i < str.length(); ++i)
        res_str[(i << 1) + 1] = str[i];
    return '$' + res_str + "#@";
}

void solve() {
    string str, str_temp;
    cin >> str;
    str_temp = preProcess(str);

    int r = 0, c = 0;
    vector<int> p(str_temp.length(), 0);
    for(int i = 1; i < str_temp.length() - 1; ++i) { 
        int mirror = 2 * c - i; 
        if(r >= i)  
            p[i] = min(p[mirror], r - i);
        
        while (str_temp[i + p[i] + 1] == str_temp[i - p[i] - 1])
            ++p[i];

        if(p[i] > r - i) { 
            c = i;
            r = i + p[i];
        }
    }

    int max_len = 0;
    for(int i = 1; i  < str_temp.length(); ++i) {
        if((i - p[i] - 1) / 2 == 0)
            max_len = max(max_len, p[i]);
    }

   cout << max_len << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}

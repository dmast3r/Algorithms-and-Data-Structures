/*
 *                        Manacher's Algorithm - Sourabh Khandelwal(themast3r, sorb1997, dmast3r)
 *          The idea is to first add some dummy characters(the function preProcess) which will help in handling both
 *          even as well as odd length palindromes, then in the modified string, considering each character as a center
 *          for a palindromic string, expand in right and left directions. Fortunately due the symmetry that palindromes
 *          follow we can use the computation done in left part to calculate the result for rigth part if we done all
 *          our computation centered around the palindromic substring with farthest right boundary.
 *          The idea is that if current index is i' it's mirror is i, and let p be an auxiliary array in which we maintain
 *          length of longest palindromic substring centered at i. The p[i'] = min(p[i], r - i'), where r is the right
 *          boundary of current palindromic substring.
 *
 *          When a new palindromic substring with farther rigth boundry is found update c(current center) and r.
 *          Finally we can get the length of largest palindromic substring by traversing the array p(and thus also the
 *          center). To obtain the longest palindromic substring use: substr((center - length - 1) / 2, length)
 */


#include <bits/stdc++.h>
using namespace std;

// A utility function to convert string str to the format $#str[0]#str[1]#str[2].......str[str.length()-1]#@
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

    int r = 0, c = 0;// initially both right boundary and center are set to 0
    vector<int> p(str_temp.length(), 0);
    for(int i = 1; i < str_temp.length() - 1; ++i) { // notice how the loop is run, we would like to skip the characters at both ends
        int mirror = 2 * c - i; // get the mirror of the current index
        if(r >= i)  // if the character at the current index is still withing the palindrome than we can
            p[i] = min(p[mirror], r - i);

        // start expanding across the center
        while (str_temp[i + p[i] + 1] == str_temp[i - p[i] - 1])
            ++p[i]; // keep the center fixed at i and expand at both ends, by incrementing the length

        if(p[i] > r - i) { // if current palindromic string exceeds the right boundary
            c = i;
            r = i + p[i];
        }
    }

    int max_palindrome_length = 0, max_palindrome_center = 1;
    for(int i = 1; i < str_temp.length() - 1; ++i) {
        if(p[i] > max_palindrome_length) {
            max_palindrome_length = p[i];
            max_palindrome_center = i;
        }
    }

    string max_palindrome = str.substr((max_palindrome_center - 1 - max_palindrome_length) / 2, max_palindrome_length);
    cout << max_palindrome_length << endl; // print length of maximum length palindromic substring
    cout << max_palindrome << endl; // print string itself.
}

int main() {
    // uncomment line 66-68 to handle multiple test cases
    //int test;
    //cin >> test;
    //while (test--)
        solve();
}

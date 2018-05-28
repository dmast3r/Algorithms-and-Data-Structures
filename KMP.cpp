#include <bits/stdc++.h>
using namespace std;

// The failureFunction finds the border for every prefix of the pattern. After the function terminates, failure[i] for every i in [1, pattern.length] will
// return the longest border(proper-prefix which is also a suffix) of the prefix ending at i. Let's denote prefix ending at i with prefix[i] for sake of
// convenience.
// Realise that if prefix[j] were a border of prefix[i] then prefix[j-1] were a border of prefix[i-1]. So, we calculate borders in bottom-up fashion, then
// all we have to do, in order to find the longest border of prefix[i], is to find all the borders(starting from the longest) of prefix[i-1] such that if
// prefix[j] is one such border of prefix[i-1] then pattern[prefix[j]] + 1 must equal pattern[i](that is next character after where the border prefix[j] ends
// must equal to the last character of prefix[i]. *** Note -  while implementing it programmatically compare pattern[prefix[j]] == pattern[i] instead as
// programming languages follow 0 based indexing. Now to get the next smaller border we can iteratively do the same thing, that is next border will be border
// of current border and hence will be given by prefix[prefix[j]]. *** Note - while implementing programmatically write prefix[prefix[j]-1] instead due to 0
// based indexing.
// But when to stop the iteratively going on above process? The answer is when the lenght of next borders we are subsequently finding reaches 0 and the
// comparison pattern[prefix[j]] == pattern[i] fails. Because the length of a border is at-least 0. We can not find any smaller border.

void failureFunction(vector<int> &failure, const string &pattern) {
    int prev_failure = 0;
    failure[0] = 0;

    // find length of the longest border for each prefix ending at the index i. After each iteration prev_failure will store the length of the longest border
    // of the previous prefix.
    for(int i = 1; i < failure.size(); ++i) {
        // while no border is found such that next character after it matches the last character of the pattern, keep doing iteration.
        // due to 0 based indexing we are comparing pattern[prev_failure] with pattern[i] and not pattern[prev_failure+1]
        while(prev_failure >= 0 and pattern[prev_failure] != pattern[i]) {
            if(prev_failure >= 1) // if the length of the border we just looked at is greater than 0, then look the next border by the iterative formula
                prev_failure = pattern[prev_failure-1]; // notice again the effect of 0 based indexing
            else
                prev_failure = -1; // the reason of setting it to -1 will be clear below
        }
        // add 1 to the longest border you found last, if the longest border were 0 and mismatch occured this should be set to 0. That's why in line 28 we
        // set prev_failure to -1, so as to nullify the effect of +1 here.
        failure[i] = ++prev_failure;
    }
}

void kmpSearch(const string &text, const string &pattern) {
    int matched = 0; // indicates the number of characters in pattern that have currently matched with the text.
    vector<int> failure(pattern.length()); // the failureArray
    failureFunction(failure, pattern); // call the failureFunction to initialise the failureArray
    int total_matches = 0; // needed in questions where you have to print total matches. Comment out if not needed.

    for(int text_pos = 0; text_pos < text.length();) {
        // while character in pattern matches with characters in text keep incrementing...
        while(matched < pattern.length() and pattern[matched] == text[text_pos]) {
            matched += 1;
            text_pos += 1;
        }

        if(matched == 0)
            ++text_pos; // if no character matched, then simply shift pattern by 1 position.
        // else start comparision of current character of text with next character of where the longest border of matched prefix
        else {
            if(matched == pattern.length()) {
                cout << text_pos - pattern.length() << endl; // if all the characters matched simply print the starting position in text where match found.
                ++total_matches; // needed in questions where you have to print total matches. Comment out if not needed.
            } // if all the characters matched simply print the starting position in text where match found.
            matched = failure[matched-1]; // matched - 1 will give the index of last matched prefix.
        }
    }
    cout << total_matches << endl; // needed in questions where you have to print total matches. Comment out if not needed.
}

void solve() {
    string text, pattern;
    cin >> text >> pattern;
    kmpSearch(text, pattern);
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}

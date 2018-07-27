/*
													By - Sourabh Khandelwal(themast3r)
	Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated sequence of dictionary 		words. See following examples for more details.

	Consider the following dictionary
	{ i, like, sam, sung, samsung, mobile, ice,
	  cream, icecream, man, go, mango}

	Input:  ilike
	Output: Yes
	The string can be segmented as "i like".

	Input:  ilikesamsung
	Output: Yes
	The string can be segmented as "i like samsung" or "i like sam sung".


	Solution:-
	Iterate through the entire list of words(that is the dictionary) and check if there is word which is a prefix of the given input text, if yes
	then remove that prefix from the text and recur for the rest of the text, that is repeat the same process. If doing this you eventually get a
	text of length 0, then you can be sure that atleast one such configuration exists, hence return true. But, if at some intermediate stage the
	entire dictionary has been scanned and not a single word exist which is a prefix of the given text then return false.

	This solution has overlapping subproblems and optimal substructure and can be thus memoized. 
*/


#include <bits/stdc++.h>
using namespace std;

// A utility function that checks if a given text can be splitted into a list of words
// dict represents the dictionary - the set of words
// n is the size of the dictionary and mp is used for memoization
// mp[text] will finally be set to true/false depending on if text can be splitted into list of words or not
bool findRecur(string text, const string dict[], int n, map<string, bool> &mp) {
	// this means entire text has been broken into pieces of text
	// so return true	
	if(text.length() == 0)
		return true;
	// if answer has been saved return it's value
	if(mp.count(text) != 0)
		return mp[text];

	// scan the entire dictionary and return an answer based on it.
	for(int i = 0; i < n; ++i) {
		string word = dict[i];
		int word_length = dict[i].length();
		
		// if dict[i] is prefix of current word then recur for the rest of the text after removing the prefix
		if(text.substr(0, word_length) == word and findRecur(text.substr(word_length, text.length() - word_length), dict, n, mp))
			return mp[text] = true;
	}
	// if all the words have been scanned and none found as prefix then return false	
	return mp[text] = false;
}

void solve() {
	int n;
	cin >> n;
	string dict[n], text;
	map<string, bool> mp;

	for(auto &i : dict)
		cin >> i;
	cin >> text;

	cout << findRecur(text, dict, n, mp) << endl;
}

int main() {
	int test;
	cin >> test;

	while(test--)
		solve();
}

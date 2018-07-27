#include <bits/stdc++.h>
using namespace std;

void findRecur(string text, const string dict[], int n, vector<string> vec) {
	if(text.length() == 0) {
		cout << "(";
		for(int i = 0; i < vec.size() - 1; ++i)
			cout << vec[i] << " ";
		cout << vec[vec.size() - 1] << ")";	
	}

	for(int i = 0; i < n; ++i) {
		string word = dict[i];
		int word_length = dict[i].length();

		if(text.substr(0, word_length) == word) {
			vec.push_back(word);
			findRecur(text.substr(word_length, text.length() - word_length), dict, n, vec);
			vec.pop_back();
		}
	}
	
	vec.clear();
}

void solve() {
	int n;
	cin >> n;
	string dict[n], text;
	vector<string> vec;

	for(auto &i : dict)
		cin >> i;
	cin >> text;

	findRecur(text, dict, n, vec);
	cout << endl;
}

int main() {
	int test;
	cin >> test;

	while(test--)
		solve();
}

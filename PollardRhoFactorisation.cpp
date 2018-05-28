#include <bits/stdc++.h>
using namespace std;

int random(int x, int n) {
	return (int(pow(x, 2)) + 1) % n;
}

int gcd(int a, int b) {
	if(b % a)
		return gcd(a, b % a);
	return a;
}

int abs(int p) {
	return (p > 0 ? p : -p);
}

pair<bool, pair<int, int>> pollardRho(int n) {
	if(n == 1)
		return make_pair(false, make_pair(0, 0));

	int hare = 2, tortoise = 2;
	do {
		tortoise = random(tortoise, n);
		hare = random(random(hare, n), n);

		int factor = gcd(n, abs(hare - tortoise));
		if(factor != 1)
			return make_pair(true, make_pair(factor, n / factor));

	} while(hare != tortoise);

	return make_pair(false, make_pair(0, 0));
}

int main() {
	int num;
	pair<bool, pair<int, int>> ans;
	cout << "Enter a number: ";
	cin >> num;

	ans = pollardRho(num);
	if(ans.first)
		cout << "Factors are: " << ans.second.first << " and " << ans.second.second;

	else
		cout << "could not find factors.";
}
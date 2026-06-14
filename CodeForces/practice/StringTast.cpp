#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

int main() {
	speed
	
	string s; cin >> s;

	unordered_set<char> vowels = {'a','e','i','o','u','y'};

	for (char c : s) {
		if (vowels.find(tolower(c)) == vowels.end()) {
			cout << '.' << (char)tolower(c);
		}
	}

	return 0;
}

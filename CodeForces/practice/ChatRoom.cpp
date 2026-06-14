#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
	speed
	
	string word = "hello";

	string s; cin >> s;

	int found = 0;

	for (char c : s) {
		if (c == word[found]) found++;
	}

	found == word.size() ? cout << "YES" : cout << "NO";

	return 0;
}

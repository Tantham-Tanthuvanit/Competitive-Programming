#include <bits/stdc++.h>
#include <cctype>
#include <string>
#include <unordered_map>

using namespace std;

#define GUMP_HUA_KUY

int main() {

	string ln; getline(cin, ln);
	map<char, int> mp;
	set<char> has = {'a','e','i','o','u'};

	for (char c : ln) {
		c = tolower(c);
		if (has.find(c) != has.end()) {
			mp[c]++;
		}
	}

	for (const auto& g : mp) {
		cout << g.first << ": " << g.second << endl;
	}

	return 0;

}

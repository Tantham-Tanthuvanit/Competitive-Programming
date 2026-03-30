#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

int main() {
	speed;

	string s; cin >> s;
	
	int bigCnt = 0;
	int smallCnt = 0;

	for (char c : s) {
		if (c >= 'a' && c <= 'z') { smallCnt++; continue; }
		if (c >= 'A' && c <= 'Z') { bigCnt++; continue; }
	}

	if (bigCnt == s.size()) cout << "All Capital Letter";
	else if (smallCnt == s.size()) cout << "All Small Letter";
	else cout << "Mix";

	return 0;
}

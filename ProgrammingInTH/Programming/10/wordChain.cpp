#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int l,n;
	cin >> l >> n;

	vector<int> maxChain(n,-1);

	string prev_word, cur_word;
	cin >> prev_word;

	int chainLen = 0;

	for (int i = 1; i < n; ++i) {
		cin >> cur_word;

		int diff = 0;
		chainLen++;

		for (int v = 0; v < l; ++v) {
			if (cur_word[v] != prev_word[i])
			diff++;
		}
		if (diff > 2) {
			maxChain.push_back(i-1);
			break;
		}

		prev_word = cur_word;
	}

	cout << prev_word;


	return 0;

}

#include <bits/stdc++.h>
#include <cmath>
#include <deque>

using namespace std;

#define ULTRA ios_base::sync_with_stdio(false);cin.tie(0);


int main() {
	ULTRA;
	
	vector<deque<int>> vec;
	deque<int> tmp;
	// start
	tmp.push_back(1);
	vec.push_back(tmp);

	for (int i = 0; i < 17; i++) {
		tmp.clear();
		for (int j = pow(2,i); j < pow(2,i+1); j++) tmp.push_back(j);
		vec.push_back(tmp);
	}

	int q; cin >> q;

	while (q--) {
		int cmd; cin >> cmd;

		if (cmd == 3) {
			int x; cin >> x;
			int level = log2(x);
			int num_index;

			for (int i = 0; i < vec[level].size(); i++)
				if (vec[level][i] == x)
					num_index = 1;

			while (level >= 0) {
				cout << vec[level][num_index] << ' ';
				--level;
				num_index>>=1; 
			}

			cout << '\n';

			continue;
		}

		if (cmd == 2) {
			int x; cin >> x;
			int k; cin >> k;
			int level = log2(x);

			if (k >= 0) {
				while (level <= 16) {
					k %= vec[level].size();
					for (int i = 1; i <= k; i++) {
						vec[level].push_front(vec[level].back());
						vec[level].pop_back();
					}
					k <<= 1;
					++level;
				}
			}
			else {
				k = -k;

				while (level <= 16) {
					k %= vec[level].size();
					for (int i = 1; i <= k; i++) {
						vec[level].push_back(vec[level].front());
						vec[level].pop_front();
					}
					k <<= 1;
					++level;
				}
			}
			continue;
		}
		else {
			int x; cin >> x;
			int k; cin >> k;
			int level = log2(x);

			if (k >= 0) {
				k %= vec[level].size();
				for (int i = 1; i <= k; i++) {
					vec[level].push_front(vec[level].back());
					vec[level].pop_back();
				}
			}
			else {
				k = -k;
				k %= vec[level].size();
				for (int i = 1; i <= k; i++) {
					vec[level].push_back(vec[level].front());
					vec[level].pop_front();
				}
			}
		}
	}
}

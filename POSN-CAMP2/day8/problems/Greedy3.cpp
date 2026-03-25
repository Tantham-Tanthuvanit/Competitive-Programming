#include <algorithm>
#include <bits/stdc++.h>
#include <functional>

using namespace std;

#define ULTRA ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
	ULTRA

	int n; cin >> n;
	vector<int> coinTypes(n);
	
	for (int i = 0; i < n; i++) 
		cin >> coinTypes[i];

	int target; cin >> target;

	//-------------------------------------------------------------
	
	vector<int> coins;

	sort(coinTypes.begin(), coinTypes.end(), greater<int>());

	while (target > 0) {
		for (int i : coinTypes) {
			if (target - i >= 0) { 
				coins.push_back(i);
				target -= i;
				break;
			}
		}
	}

	cout << coins.size() << endl;

	for (int i : coins)
		cout << i << ' ';

}

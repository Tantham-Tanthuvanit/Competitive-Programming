#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main() {
	int count;
	cin >> count;
	int mn = 10000000;
	int mx = 0;
	
	float sum = 0;
	map<int,string> mp;

	for (int i = 0; i < count; i++) {
		int n = 0;
		string name;
		cin >> name >> n;
		sum += n;

		mp[n] = name;
		mn = min(n, mn);
		mx = max(n, mx);
	}

	cout << mp[mx] << '\n' << mp[mn] << '\n' << sum / count;
}

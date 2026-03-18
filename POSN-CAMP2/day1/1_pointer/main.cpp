#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

int main() {

	int n;

	cin >> n;

	vector<int> men(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> men[i];
	}

	sort(men.begin(), men.end());

	int menue;
	cin >> menue;

	if (menue == 1) {
		for (auto c : men) cout << c << endl;
		return 0;
	}

	if (menue == 2) {
		cout << men[men.size()-1];
		return 0;
	}

	cout << men[0];

	return 0;

}

#include <iostream>
#include <vector>
using namespace std;

int maxWater(vector<int>& arr) {
    int n = arr.size();

    vector<int> left(n);

    vector<int> right(n);

    int res = 0;

    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);

    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);

    for (int i = 1; i < n - 1; i++) {
        int minOf2 = min(left[i], right[i]);
            res += minOf2 - arr[i];
    }

    return res;
}

int main() {
	int n; cin >> n;

	if (n < 3) {
		cout << 0;
		return 0;
	}

	vector<int> walls(n);
	for (int i = 0; i < n; i++)
		cin >> walls[i];

    cout << maxWater(walls);
    return 0;
}

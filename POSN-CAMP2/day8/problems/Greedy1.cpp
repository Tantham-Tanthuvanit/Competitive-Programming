#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>

using namespace std;

#define ULTRA ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {

	ULTRA

	// weight and value / weight
	priority_queue<pair<double, int>> valueByWeight;
	int n, capacity; cin >> n >> capacity;

	for (int i = 0; i < n; ++i) {
		int weight, value; cin >> weight >> value;
		valueByWeight.push({(double)value/weight, weight});
	}

	int sum = 0;

	for (int i = 0; i < n && capacity > 0; ++i) {
		if (capacity - valueByWeight.top().second >= 0) {
			sum += valueByWeight.top().second * valueByWeight.top().first;
			capacity -= valueByWeight.top().second;
		}
		valueByWeight.pop();
	}

	cout << sum;

	return 0;

}

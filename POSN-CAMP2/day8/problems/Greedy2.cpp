#include <bits/stdc++.h>
#include <queue>

using namespace std;

#define item pair<double,pair<int,int>>
#define ULTRA ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
	priority_queue<item> pq;
	int n,capacity; cin >> n >> capacity;

	int a = n;
	while (a--) {
		int weight, value;
		cin >> weight >> value;
		pq.push({(double)value/weight, {value,weight}});
	}

	int sum = 0;

	for (int i = 0; i < n && capacity > 0; i++) {
		item top = pq.top(); pq.pop();
		double ratio = top.first;
		int value = top.second.first;
		int weight = top.second.second;

		if (capacity - weight >= 0) {
			sum += ratio * weight;
			capacity -= weight;
		} else {
			sum += ratio * capacity;
			capacity = 0;
		}
	}

	cout << sum;

	return 0;
}

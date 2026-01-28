#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>

using namespace std;

unordered_map<int, int> mp;

auto max_it = std::max_element(
	mp.begin(),mp.end(),
	[](const pair<int, int>& a, const pair<int, int>& b) {
		return a.second < b.second;
	}
);

int main() {
	return 0;
}

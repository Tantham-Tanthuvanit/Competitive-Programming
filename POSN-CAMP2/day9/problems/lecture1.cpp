#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

// H(x) = 2*H(x-1) + 3*H(x-2) + 3
// H(0) = 1
// h(1) = 3

unordered_map<int, int> lookup;

int H(int x) {
	if (lookup[x]) return lookup[x];
	if (x <= 1) return (x*2)+1;

	lookup[x] = 2*H(x-1) + 3*H(2-2) + 3;
	return lookup[x];
}

int main() {

	return 0;

}

#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

struct vec3 {
	int x;
	int y;
	int z;
};

int main () {
	speed

	vec3 sum = {0,0,0};

	int n; cin >> n;

	while (n--) {
		int a,b,c; cin >> a >> b >> c;
		sum.x += a;
		sum.y += b;
		sum.z += c;
	}

	sum.x == 0 && sum.y == 0 && sum.z == 0 ? cout << "YES" : cout << "NO";

	return 0;
}



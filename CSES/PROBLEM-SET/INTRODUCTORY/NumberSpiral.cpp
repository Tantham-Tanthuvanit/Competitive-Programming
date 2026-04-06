#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t; cin >> t;
    while (t--) {
        int y, x; cin >> y >> x;

        int k = max(x, y);

        if (k % 2 == 0) {
            if (y == k)
                cout << k*k - x + 1 << '\n';
            else
                cout << (k-1)*(k-1) + y << '\n';
        } else {
            if (x == k)
                cout << k*k - y + 1 << '\n';
            else
                cout << (k-1)*(k-1) + x << '\n';
        }
    }
}

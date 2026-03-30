#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];

    int i = 0, j = 0;
    long long res = 1; // count starting point (0,0)

    while (i < n && j < m) {
        long long L1 = (i == 0 ? 0 : a[i-1]);
        long long R1 = a[i];

        long long L2 = (j == 0 ? 0 : b[j-1]);
        long long R2 = b[j];

        // Case 1: both hit wall at same position
        if (R1 == R2) {
            res++;
            i++;
            j++;
        } 
        else {
            // Case 2: segments overlap (including boundary)
            if (max(L1, L2) <= min(R1, R2)) {
                // must have opposite slopes
                if ((i % 2) != (j % 2)) {
                    res++;
                }
            }

            // move pointer with smaller endpoint
            if (R1 < R2) i++;
            else j++;
        }
    }

    cout << res << '\n';
    return 0;
}
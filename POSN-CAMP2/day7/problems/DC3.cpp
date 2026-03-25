#include <bits/stdc++.h>
using namespace std;

#define ULTRA ios_base::sync_with_stdio(false); cin.tie(nullptr);

int maxCrossingSum(vector<int>& v, int low, int mid, int high) {
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = mid; i >= low; i--) {
        sum += v[i];
        if (sum > left_sum) left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int i = mid + 1; i <= high; i++) {
        sum += v[i];
        if (sum > right_sum) right_sum = sum;
    }

    return left_sum + right_sum;
}

int solve(vector<int>& v, int low, int high) {
    // Base case only one element
    if (low == high) return v[low];

    int mid = low + (high - low) / 2;

    return max({
        solve(v, low, mid),
        solve(v, mid + 1, high),
        maxCrossingSum(v, low, mid, high)
    });
}

int main() {
    ULTRA
    int n; 
    if (!(cin >> n)) return 0;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    if (n == 0) cout << 0;
    else cout << solve(v, 0, n - 1);

    return 0;
}
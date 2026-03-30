#include <bits/stdc++.h>
using namespace std;
#define speed = ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long

signed main() {

    // input handling
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int current_sum = 0, max_sum = 0;
    int temp_start = 0;
    int best_start = -1, best_end = -1;

    for (int i = 0; i < n; i++) {
        current_sum += arr[i];

        if (current_sum > max_sum) {
            max_sum = current_sum;
            best_start = temp_start;
            best_end = i;
        }

        if (current_sum < 0) {
            current_sum = 0;
            temp_start = i + 1;
        }
    }

    if (max_sum == 0) {
        cout << "Empty sequence";
        return 0;
    }

    for (int i = best_start; i <= best_end; ++i) {
        cout << arr[i] << ' ';
    }

    cout << endl;

    cout << max_sum;

    return 0;
}
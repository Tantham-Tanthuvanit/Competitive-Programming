#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

int main() {
    speed

    int t; cin >> t;

    string ans = "";

    while (t--) {
        int k; cin >> k;
        vector<int> p(k);

        for (int i = 0; i < k; ++i)
            cin >> p[i];

        set<int> winners; 
        int pref = 0;

        for (int i = 0; i < k; ++i) {
            pref += p[i];
            winners.insert(pref % k);
        }

        ans += to_string(winners.size()) + '\n';
    }

    cout << ans;
    return 0;
}
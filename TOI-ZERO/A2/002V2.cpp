#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>

int main() {
    int n; cin >> n;
    unordered_map<int, pii> diag1,diag2;

    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;

        int d1 = x - y;
        int d2 = x + y;

        if (!diag1.count(d1))
            diag1[d1] = {x,x};
        else {
            diag1[d1].first = min(diag1[d1].first,x);
            diag1[d1].second = max(diag1[d1].second,x);
        }
        if (!diag2.count(d2))
            diag2[d2] = {x,x};
        else {
            diag2[d2].first = min(diag2[d2].first,x);
            diag2[d2].second = max(diag2[d2].second,x);
        }
    }

    int maxSize = 0;

    for (auto& it : diag1)
        maxSize = max(maxSize, it.second.second - it.second.first);

    for (auto& it : diag2)
        maxSize = max(maxSize, it.second.second - it.second.first);

    cout << maxSize;
    return 0;
}
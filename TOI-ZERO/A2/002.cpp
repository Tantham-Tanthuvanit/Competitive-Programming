#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(fasle);cin.tie(NULL);
#define pii pair<int,int>

int main() {
    int n; cin >> n;
    vector<pii> points;
    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        points.push_back({x,y});
    }

    if (points.empty()) {
        cout << 0;
        return 0;
    }
    sort(points.begin(),points.end());

    int maxSize = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j)
            if (abs(points[i].first - points[j].first) == abs(points[i].second - points[j].second))
                maxSize = max(abs(points[i].first-points[j].first), maxSize);
    }

    cout << maxSize;

    return 0;
}

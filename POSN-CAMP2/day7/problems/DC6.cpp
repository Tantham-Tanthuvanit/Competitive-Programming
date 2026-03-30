#include <bits/stdc++.h>
using namespace std;

struct Event {
    int x;
    int h;
    int type; // 1 for Start, -1 for End

    // Sorting logic: Sort by X. If X is the same, process Starts before Ends.
    bool operator<(const Event& other) const {
        if (x != other.x) return x < other.x;
        return type > other.type; 
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Event> events;
    for (int i = 0; i < n; i++) {
        int l, r, h;
        cin >> l >> r >> h;
        events.push_back({l, h, 1});  // Wall starts
        events.push_back({r, h, -1}); // Wall ends
    }

    sort(events.begin(), events.end());

    multiset<int> activeHeights;
    activeHeights.insert(0); // Ground level always exists

    int currentMax = 0;

    for (auto& e : events) {
        if (e.type == 1) {
            activeHeights.insert(e.h);
        } else {
            auto it = activeHeights.find(e.h);
            if (it != activeHeights.end()) {
                activeHeights.erase(it);
            }
        }

        int newMax = *activeHeights.rbegin();

        if (newMax != currentMax) {
            cout << e.x << " " << newMax << "\n";
            currentMax = newMax;
        }
    }

    return 0;
}
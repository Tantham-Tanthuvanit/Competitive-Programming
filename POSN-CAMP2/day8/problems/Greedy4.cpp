#include <bits/stdc++.h>
using namespace std;

struct Fruit {
    int id;
    double density;
    int V, B, P;
};

int main() {
    int M; cin >> M;

    vector<Fruit> fruits(M);

    for (int i = 0; i < M; i++) {
        cin >> fruits[i].V >> fruits[i].B >> fruits[i].P;
        fruits[i].id = i;
        fruits[i].density = (double)fruits[i].V / (fruits[i].B * fruits[i].P);
    }

    double W; cin >> W;
    int capacity = (int)(W * 1000); // kg

    // sort by value density DESC
    sort(fruits.begin(), fruits.end(), [](auto &a, auto &b) {
        return a.density > b.density;
    });

    vector<int> box(M, 0), bag(M, 0);

    for (auto &f : fruits) {
        if (capacity <= 0) break;

        // take boxes
        int take_boxes = min(f.B, capacity / f.P);
        box[f.id] = take_boxes;

        capacity -= take_boxes * f.P;

        // take bags
        int remaining_bags = f.B * f.P - take_boxes * f.P;
        int take_bags = min(capacity, remaining_bags);

        bag[f.id] = take_bags;
        capacity -= take_bags;
    }

    // output in original order
    for (int i = 0; i < M; i++) {
        cout << box[i] << " " << bag[i] << "\n";
    }

    return 0;
}

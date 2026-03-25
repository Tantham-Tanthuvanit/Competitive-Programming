#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> arr) {
    // base case (if arr has 1 element or empty its sorted)
    if (arr.size() <= 1) return arr;

    // divide
    int mid = ((arr.size()+1)/2);
    vector<int> l(arr.begin(), arr.begin() + mid);
    vector<int> r(arr.begin() + mid, arr.end());

    //cout << "l ";
    //for (int i : l) {
    //    cout << i << ' ';
    //}
    //cout << endl;

    //cout << "r ";
    //for (int i : r) {
    //    cout << i << ' ';
    //}
    //cout << endl;

    l = merge(l);
    r = merge(r);

    // con
    int leftPtr = 0;
    int rightPtr = 0;
    int mainPtr = 0;

    while (leftPtr < l.size() && rightPtr < r.size()) {
        if (l[leftPtr] < r[rightPtr]) {
            arr[mainPtr] = l[leftPtr];
            leftPtr++;
        } else {
            arr[mainPtr] = r[rightPtr];
            rightPtr++;
        }
        mainPtr++;
    }

    // cleanup (add remaining elements)
    while (leftPtr < l.size()) arr[mainPtr++] = l[leftPtr++];
    while (rightPtr < r.size()) arr[mainPtr++] = r[rightPtr++];

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << ' ';
    }
    cout << endl; //<< "-------------------------------" << endl;

    return arr;

}

int main() {

    int n; cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    merge(v);

    return 0;
}
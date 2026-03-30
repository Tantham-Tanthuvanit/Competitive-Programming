#include <bits/stdc++.h>
using namespace std;

// Binary Search in C++

#include <iostream>
using namespace std;

bool binarySearch(vector<int> array, int target, int low, int high) {
  
	// Repeat until the pointers low and high meet each other
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (target == array[mid])
      return true;

    if (target > array[mid])
      low = mid + 1;

    else
      high = mid - 1;
  }

  return false;
}

int main() {

    int n; cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        if (binarySearch(v, x, 0, v.size()-1)) cout << "Found" << endl;
        else cout << "Not found" << endl;
    }

}
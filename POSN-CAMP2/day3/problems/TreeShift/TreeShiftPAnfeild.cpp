#include <bits/stdc++.h>
using namespace std;

const int pow2[18] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<deque<int>>vec;
    deque<int>tmp;
    tmp.push_back(1);
    vec.push_back(tmp);
    
    for (int i=1; i<17; i++) {
        tmp.clear();
        for (int j=pow2[i]; j<pow2[i+1]; j++) tmp.push_back(j);
        vec.push_back(tmp);
    }

    int q;
    cin >> q;

    while (q--) {
        int order;
        cin >> order;

        if (order == 3) {
            int x;
            cin >> x;
            int level = log2(x);
            int num_index;

            for (int i=0; i<vec[level].size(); i++) {
                if (vec[level][i] == x) {
                    num_index = i;
                }
            }
            while (level >= 0) {
                cout << vec[level][num_index] << " ";
                --level;
                num_index>>=1;
            }
            cout << "\n";
        }
        else if (order == 2) {
            int x;
            cin >> x;
            int k;
            cin >> k;
            int level = log2(x);

            if (k>=0) {
                while (level <= 16) {
                    k %= vec[level].size();
                    for (int i=1; i<=k; i++) {
                        vec[level].push_front(vec[level].back());
                        vec[level].pop_back();
                    }
                    k<<=1;
                    ++level;
                }
            }
            else {
                k = -k;

                while (level <= 16) {
                    k %= vec[level].size();
                    for (int i=1; i<=k; i++) {
                        vec[level].push_back(vec[level].front());
                        vec[level].pop_front();
                    }
                    k<<=1;
                    ++level;
                }
            }
        }
        else {
            int x;
            cin >> x;
            int k;
            cin >> k;
            int level = log2(x);

            if (k >= 0) {
                k %= vec[level].size();
                for (int i=1; i<=k; i++) {
                    vec[level].push_front(vec[level].back());
                    vec[level].pop_back();
                }
            }
            else {
                k = -k;
                k %= vec[level].size();
                for (int i=1; i<=k; i++) {
                    vec[level].push_back(vec[level].front());
                    vec[level].pop_front();
                }
            }
        }
    }
    
}

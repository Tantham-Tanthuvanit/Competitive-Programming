#include <vector>
#include <unordered_map>

using namespace std;

// put a and b into seperate hashmaps
// check for each index of A if theres the same number in B if so then add to a count

class Solution {
public:
	vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
		
		vector<int> ans(A.size());
		unordered_map<int,int> anums;
		unordered_map<int,int> bnums;

		int count = 0;

		for (int i = 0; i < A.size(); i++) {
			anums[A[i]]++;
			if (bnums[A[i]] == 1) count++;

			bnums[B[i]]++;
			if (anums[B[i]] == 1) count++;

			ans[i] = count;
		}

		return ans;

	}
};

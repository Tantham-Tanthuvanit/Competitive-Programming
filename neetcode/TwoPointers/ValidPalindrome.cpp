#include "config.h"

class Solution {
	public:
		bool isPalindrome(string s) {

			string ns;
			for (char c : s)
				if (isalnum(c)) ns += c;

			int l = 0;
			int r = ns.size()-1;

			while (l < r) {
				if (tolower(ns[l]) != tolower(ns[r])) return false;
				l++;
				r--;
			}

			return true;
		}
};

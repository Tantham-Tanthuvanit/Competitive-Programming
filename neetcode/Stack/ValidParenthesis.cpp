#include "config.h"

class Solution {
	public:
		bool isValid(string s) {
			stack<char> st;
			for (auto& c : s) {
				if (c == '(' || c == '{' || c == '[') st.emplace(c);
				else {
					if (st.empty()) return false;
					if (c == ')') {
						if (st.top() == '(') st.pop();
						else return false;
					}

					else if (c == '}') {
						if (st.top() == '{') st.pop();
						else return false;
					}

					else if (c == ']') {
						if (st.top() == '[') st.pop();
						else return false;
					}
				}
			}

			if (!st.empty()) return false;
			return true;
		}
};

#include "config.h"

class Solution {
	public:
		int evalRPN(vector<string>& tokens) {
			stack<int> stk;

			for (auto& token : tokens) {
				if (token == "+") {
					int a = stk.top(); stk.pop();
					int b = stk.top(); stk.pop();

					stk.push(a + b);
				}
				else if (token == "-") {
					int a = stk.top(); stk.pop();
					int b = stk.top(); stk.pop();

					stk.push(b - a);
				}
				else if (token == "*") {
					int a = stk.top(); stk.pop();
					int b = stk.top(); stk.pop();

					stk.push(a * b);
				}
				else if (token == "/") {
					int a = stk.top(); stk.pop();
					int b = stk.top(); stk.pop();

					stk.push(b / a);
				}
				else stk.push(stoi(token));
			}

			if (stk.empty()) return 0;
			return stk.top();
		}
};

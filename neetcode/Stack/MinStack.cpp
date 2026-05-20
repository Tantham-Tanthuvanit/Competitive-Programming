#include "config.h"

class MinStack {
	public:

		stack<int> stck;
		stack<int> minStck;

		MinStack() {
		}

		void push(int val) {
			stck.push(val);
			// pushes the minimum value to the top of the stack
			minStck.push(min(val,minStck.empty() ? val : minStck.top()));
		}

		void pop() {
			stck.pop();
			minStck.pop();
		}

		int top() {
			return stck.top();
		}

		int getMin() {
			return minStck.top();
		}
};

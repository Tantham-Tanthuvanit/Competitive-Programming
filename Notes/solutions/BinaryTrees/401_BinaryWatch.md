# 401 BINARY WATCH
- [LEETCODE LINK](https://leetcode.com/problems/binary-watch/?envType=problem-list-v2&envId=backtracking)
- ==DIFFICULTY        :   EASY==
- ==DATE COMPLETED  :   3/13/2026 @ 3:59AM==
---

> [!WARNING] ITS NOT A FUCKING BACKTRACKING PROBLEM

## PERSONAL NOTES
Not anything that hard tbh, overthought it when I thought it was a backtracking problem

---
## TASK STATEMENT
A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the right.

    For example, the below binary watch reads "4:51".

Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM), return all possible times the watch could represent. You may return the answer in any order.

The hour must not contain a leading zero.

    For example, "01:00" is not valid. It should be "1:00".

The minute must consist of two digits and may contain a leading zero.

    For example, "10:2" is not valid. It should be "10:02".

 

Example 1:
- Input: turnedOn = 1
- Output: ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]

Example 2:
- Input: turnedOn = 9
- Output: []

> [!NOTE] TLDR
> Return an array of all the times that has the same 1 bits as the input number
---
## SOLUTION

### INTUITION
Loop through hours 0 - 11 and 0 - 59 mins, only 720 possible cases so its plenty fast
and a very simple solution

### CODE IMPLEMENTATION
```cpp
class Solution {
public:
	vector<string> readBinaryWatch(int turnedOn) {
		vector<string> ans;

		for (int h = 0; h < 12; h++) {
			for (int m = 0; m < 60; m++) {

				int bits = __builtin_popcount(h) + __builtin_popcount(m);

				if (bits == turnedOn) {
					string time = to_string(h) + ":";

					if (m < 10)
						time += "0";

					time += to_string(m);

					ans.push_back(time);
				}

			}
		}

		return ans;

	}
};
```

#### EXPLANATION
1. Create ans vector
```cpp
vector<string> ans;
```

2. Loop through hours and mins
```cpp
for (int h = 0; h < 12; h++)
    for (int m = 0; m < 60; m++)
```

3. Use builtin function to calculate the number of 1 bits in the binary version of the number
```cpp
int bits = __builtin_popcount(h) + __builtin_popcount(m);
```

4. Check if number of bits is equal to the input and if so then add the apropriate time string
```cpp
if (bits == turnedOn) {
	string time = to_string(h) + ":";

	if (m < 10)
        time += "0";

    time += to_string(m);

    ans.push_back(time);
}

```

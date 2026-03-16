# BACKTRACKING

> [!NOTE] Most backtracking problems follow the same template
```cpp
    void backtrack(parameters) {

    // 1️⃣ base case (optional depending on problem)
    if (done_condition) {
        result.push_back(current_state);
        return;
    }

    // 2️⃣ try all choices
    for (each possible choice) {

        // choose
        make_choice();

        // explore
        backtrack(next_state);

        // undo choice (BACKTRACK)
        undo_choice();
    }
}

```
## Most important steps are:
1. choose
2. explore
3. undo

## SUBSET TEMPLATE
```cpp
class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, vector<int>& path, int start) {

        result.push_back(path);   // save subset

        for (int i = start; i < nums.size(); i++) {

            path.push_back(nums[i]);          // choose

            backtrack(nums, path, i + 1);     // explore

            path.pop_back();                  // undo
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        backtrack(nums, path, 0);
        return result;
    }
};
```

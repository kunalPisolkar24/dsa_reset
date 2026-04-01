#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }

private:
    void backtrack(const vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        // Record current combination (every node is a unique subset)
        result.push_back(current);

        for (int i = start; i < (int)nums.size(); i++) {
            // Sibling skipping for duplicate handling
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, result);
            current.pop_back();
        }
    }
};

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        vector<int> current;
        vector<bool> visited(nums.size(), false);
        backtrack(nums, visited, current, result);
        return result;
    }

private:
    void backtrack(const vector<int>& nums, vector<bool>& visited, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < (int)nums.size(); i++) {
            if (visited[i]) continue;
            
            // DUPLICATE HANDLING:
            // If current element is same as previous, and previous hasn't been visited 
            // in this specific recursive path, skip it to avoid redundant permutations.
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }

            visited[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, visited, current, result);
            current.pop_back();
            visited[i] = false;
        }
    }
};

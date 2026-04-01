#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combineUnique(vector<int>& nums, int k) {
        vector<vector<int>> result;
        if (k == 0) {
            result.push_back({});
            return result;
        }
        sort(nums.begin(), nums.end());
        vector<int> current;
        backtrack(nums, 0, k, current, result);
        return result;
    }

private:
    void backtrack(const vector<int>& nums, int start, int k, vector<int>& current, vector<vector<int>>& result) {
        if ((int)current.size() == k) {
            result.push_back(current);
            return;
        }

        // Pruning: if remaining elements + current elements < k, return
        if ((int)current.size() + ((int)nums.size() - start) < k) {
            return;
        }

        for (int i = start; i < (int)nums.size(); i++) {
            // Sibling skipping for duplicate handling
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            current.push_back(nums[i]);
            backtrack(nums, i + 1, k, current, result);
            current.pop_back();
        }
    }
};

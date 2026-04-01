#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSumK(vector<int>& nums, int target, int k) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        vector<int> current;
        backtrack(nums, 0, 0, target, k, current, result);
        return result;
    }

private:
    void backtrack(const vector<int>& nums, int start, int currentSum, int target, int k, vector<int>& current, vector<vector<int>>& result) {
        if ((int)current.size() == k) {
            if (currentSum == target) {
                result.push_back(current);
            }
            return;
        }

        for (int i = start; i < (int)nums.size(); i++) {
            // Pruning: if current sum + nums[i] > target, stop loop
            if (currentSum + nums[i] > target) {
                break;
            }

            current.push_back(nums[i]);
            // UNLIMITED: Pass 'i' instead of 'i + 1' to allow reusing the same element
            backtrack(nums, i, currentSum + nums[i], target, k, current, result);
            current.pop_back();
        }
    }
};

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSumDuplicate(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        // Deduplicate and sort input candidates
        set<int> uniqueCandidates(candidates.begin(), candidates.end());
        vector<int> nums(uniqueCandidates.begin(), uniqueCandidates.end());
        
        vector<int> current;
        backtrack(nums, 0, 0, target, current, result);
        return result;
    }

private:
    void backtrack(const vector<int>& nums, int start, int currentSum, int target, vector<int>& current, vector<vector<int>>& result) {
        if (currentSum == target) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < (int)nums.size(); i++) {
            if (currentSum + nums[i] > target) {
                break;
            }

            current.push_back(nums[i]);
            // UNLIMITED: Pass 'i' instead of 'i + 1'
            backtrack(nums, i, currentSum + nums[i], target, current, result);
            current.pop_back();
        }
    }
};

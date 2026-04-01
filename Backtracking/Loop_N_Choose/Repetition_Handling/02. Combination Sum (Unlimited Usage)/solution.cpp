#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        vector<int> current;
        backtrack(candidates, 0, 0, target, current, result);
        return result;
    }

private:
    void backtrack(const vector<int>& candidates, int start, int currentSum, int target, vector<int>& current, vector<vector<int>>& result) {
        if (currentSum == target) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < (int)candidates.size(); i++) {
            // Pruning: if current sum + candidates[i] > target, stop loop
            if (currentSum + candidates[i] > target) {
                break;
            }

            current.push_back(candidates[i]);
            // UNLIMITED: Pass 'i' instead of 'i + 1' to allow reusing the same element
            backtrack(candidates, i, currentSum + candidates[i], target, current, result);
            current.pop_back();
        }
    }
};

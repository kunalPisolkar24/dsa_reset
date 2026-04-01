#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
            // Sibling skipping for duplicate handling
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Pruning: since elements are positive and sorted
            if (currentSum + candidates[i] > target) {
                break;
            }

            current.push_back(candidates[i]);
            backtrack(candidates, i + 1, currentSum + candidates[i], target, current, result);
            current.pop_back();
        }
    }
};

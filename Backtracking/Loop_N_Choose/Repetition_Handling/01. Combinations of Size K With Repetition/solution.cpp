#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combineWithRepetition(vector<int>& nums, int k) {
        vector<vector<int>> result;
        if (k == 0) {
            result.push_back({});
            return result;
        }
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

        for (int i = start; i < (int)nums.size(); i++) {
            current.push_back(nums[i]);
            // REPETITION: Pass 'i' instead of 'i + 1' to allow reusing the same element
            backtrack(nums, i, k, current, result);
            current.pop_back();
        }
    }
};

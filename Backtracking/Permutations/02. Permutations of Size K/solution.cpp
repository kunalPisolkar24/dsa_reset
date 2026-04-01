#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteK(vector<int>& nums, int k) {
        vector<vector<int>> result;
        if (k > (int)nums.size()) {
            return result;
        }
        vector<int> current;
        vector<bool> visited(nums.size(), false);
        backtrack(nums, visited, current, result, k);
        return result;
    }

private:
    void backtrack(const vector<int>& nums, vector<bool>& visited, vector<int>& current, vector<vector<int>>& result, int k) {
        if ((int)current.size() == k) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < (int)nums.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                current.push_back(nums[i]);
                backtrack(nums, visited, current, result, k);
                current.pop_back();
                visited[i] = false;
            }
        }
    }
};

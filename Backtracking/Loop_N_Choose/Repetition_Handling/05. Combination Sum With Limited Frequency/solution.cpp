#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSumFreq(vector<int>& nums, vector<int>& freq, int target) {
        vector<vector<int>> result;
        // Sort both nums and freq based on nums
        vector<pair<int, int>> zipped;
        for (int i = 0; i < (int)nums.size(); i++) zipped.push_back({nums[i], freq[i]});
        sort(zipped.begin(), zipped.end());
        vector<int> sortedNums, sortedFreq;
        for (auto& p : zipped) {
            sortedNums.push_back(p.first);
            sortedFreq.push_back(p.second);
        }

        vector<int> current;
        backtrack(sortedNums, sortedFreq, 0, 0, target, current, result);
        return result;
    }

private:
    void backtrack(const vector<int>& nums, const vector<int>& freq, int index, int currentSum, int target, vector<int>& current, vector<vector<int>>& result) {
        if (currentSum == target) {
            result.push_back(current);
            return;
        }
        if (index == (int)nums.size()) {
            return;
        }

        // Try using nums[index] from 0 to freq[index] times
        int originalSize = current.size();
        for (int count = 0; count <= freq[index]; count++) {
            if (count > 0) {
                if (currentSum + nums[index] > target) break;
                current.push_back(nums[index]);
                currentSum += nums[index];
            }
            backtrack(nums, freq, index + 1, currentSum, target, current, result);
        }
        
        // Backtrack: restore current vector and sum
        while ((int)current.size() > originalSize) {
            current.pop_back();
        }
    }
};

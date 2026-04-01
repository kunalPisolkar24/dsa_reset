#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsequencesWithSumAtMostK(vector<int>& arr, int target) {
        vector<vector<int>> result;
        vector<int> current;
        generateRecursive(arr, 0, 0, target, current, result);
        return result;
    }

private:
    void generateRecursive(const vector<int>& arr, int index, int currentSum, int target, vector<int>& current, vector<vector<int>>& result) {
        // Base case: finished processing all elements
        if (index == arr.size()) {
            // Check if current subsequence is non-empty and has sum <= target
            // (Sum logic is handled during recursion for pruning)
            if (!current.empty() && currentSum <= target) {
                result.push_back(current);
            }
            return;
        }

        // Option 1: Pick arr[index] (Only if sum doesn't exceed target)
        if (currentSum + arr[index] <= target) {
            current.push_back(arr[index]);
            generateRecursive(arr, index + 1, currentSum + arr[index], target, current, result);
            current.pop_back();
        }

        // Option 2: Not-pick arr[index]
        generateRecursive(arr, index + 1, currentSum, target, current, result);
    }
};

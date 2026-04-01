#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsequencesOfLengthK(vector<int>& arr, int k) {
        vector<vector<int>> result;
        vector<int> current;
        generateRecursive(arr, 0, k, current, result);
        return result;
    }

private:
    void generateRecursive(const vector<int>& arr, int index, int k, vector<int>& current, vector<vector<int>>& result) {
        // Base case: exactly k elements collected
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        // Base case: no more elements to pick
        if (index == arr.size()) {
            return;
        }

        // Pruning: if remaining elements + current elements < k, we can't reach k
        if (current.size() + (arr.size() - index) < k) {
            return;
        }

        // Option 1: Pick arr[index]
        current.push_back(arr[index]);
        generateRecursive(arr, index + 1, k, current, result);
        current.pop_back();

        // Option 2: Not-pick arr[index]
        generateRecursive(arr, index + 1, k, current, result);
    }
};

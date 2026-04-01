#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(vector<int>& arr, int k) {
        vector<vector<int>> result;
        if (k == 0) {
            result.push_back({});
            return result;
        }
        vector<int> current;
        backtrack(arr, 0, k, current, result);
        return result;
    }

private:
    void backtrack(const vector<int>& arr, int start, int k, vector<int>& current, vector<vector<int>>& result) {
        if ((int)current.size() == k) {
            result.push_back(current);
            return;
        }

        // Pruning: if remaining elements + current elements < k, return
        if ((int)current.size() + ((int)arr.size() - start) < k) {
            return;
        }

        for (int i = start; i < (int)arr.size(); i++) {
            current.push_back(arr[i]);
            backtrack(arr, i + 1, k, current, result);
            current.pop_back();
        }
    }
};

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findFirst(vector<int>& arr, int target) {
        int n = arr.size(); 
        int ans = -1;
        function<void(int)> sol = [&](int idx) -> void {
            if(ans != -1 or idx >= n) return;
            if(arr[idx] == target) {
                ans = idx;
                return;
            }
            sol(idx + 1);
        };
        sol(0);
        return ans;
    }
};

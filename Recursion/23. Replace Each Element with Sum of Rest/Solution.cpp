#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> replaceWithSum(vector<int> &arr) {
    int sum = 0;
    function<void(int)> sol = [&](int idx) -> void {
        if(idx >= arr.size()) return;
        sum += arr[idx];
        sol(idx + 1);
        arr[idx] = sum - arr[idx];
    };
    sol(0);
    return arr;
  }
};

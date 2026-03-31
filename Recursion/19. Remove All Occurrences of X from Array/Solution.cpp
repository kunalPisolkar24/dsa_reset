#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> removeX(vector<int> &arr, int x) {
    function<void(vector<int>&)> sol = [&](vector<int> &a) -> void {
        if(a.empty()) return;
        int temp = a.back();
        a.pop_back();
        sol(a);
        if(temp != x) a.push_back(temp);
    };
    sol(arr);
    return arr;
  }
};

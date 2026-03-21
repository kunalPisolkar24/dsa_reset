#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> printEven(int N) {
        vector<int> res;
        function<void(int)> sol = [&](int n) -> void {
            if(n > N) return;
            res.push_back(n);
            sol(n + 2);
        };
        sol(2);
        return res;
    }
};

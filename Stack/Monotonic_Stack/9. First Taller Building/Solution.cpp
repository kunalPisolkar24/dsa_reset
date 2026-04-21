#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> firstTallerBuilding(vector<int>& heights) {
        int n = heights.size();
        vector<int> res(n, 0);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() and st.top() <= heights[i]) {
                st.pop();
            }
            res[i] = st.empty() ? -1 : st.top();
            st.push(heights[i]);
        }
        return res;
    }
};

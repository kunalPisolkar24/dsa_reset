#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> sortByLength(vector<string> arr) {
        sort(arr.begin(), arr.end(), [](string &a, string &b) {
            if(a.length() == b.length()) 
                return a < b;
            return a.length() < b.length();
        });
        return arr;
    }
};

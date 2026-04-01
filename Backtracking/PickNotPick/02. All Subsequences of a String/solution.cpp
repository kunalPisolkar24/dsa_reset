#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> subsequences(string s) {
        vector<string> result;
        string current = "";
        generateRecursive(s, 0, current, result);
        return result;
    }

private:
    void generateRecursive(const string& s, int index, string& current, vector<string>& result) {
        if (index == s.length()) {
            result.push_back(current);
            return;
        }

        // Option 1: Pick s[index]
        current.push_back(s[index]);
        generateRecursive(s, index + 1, current, result);
        current.pop_back();

        // Option 2: Not-pick s[index] (skip it)
        generateRecursive(s, index + 1, current, result);
    }
};

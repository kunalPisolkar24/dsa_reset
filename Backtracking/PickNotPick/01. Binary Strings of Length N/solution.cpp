#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> generate(int n) {
        vector<string> result;
        string current = "";
        generateRecursive(n, current, result);
        return result;
    }

private:
    void generateRecursive(int n, string& current, vector<string>& result) {
        if (current.length() == n) {
            result.push_back(current);
            return;
        }

        // Option 1: Pick '0'
        current.push_back('0');
        generateRecursive(n, current, result);
        current.pop_back();

        // Option 2: Pick '1'
        current.push_back('1');
        generateRecursive(n, current, result);
        current.pop_back();
    }
};

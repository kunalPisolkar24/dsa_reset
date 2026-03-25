#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isBitSet(int n, int i) {
        return ((n >> i) & 1);
    }
};

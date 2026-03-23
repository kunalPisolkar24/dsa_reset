#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int countSubstringsWithKBad(string s, vector<char> &bad, int k) {
    int n = s.size();
    unordered_set<char> bads;
    for (int i = 0; i < bad.size(); i++) {
      bads.insert(bad[i]);
    }

    auto sol = [&](int k) -> int {
      if (k < 0)
        return 0;
      int left = 0, count = 0, badCount = 0;
      for (int right = 0; right < n; right++) {
        badCount += (bads.count(s[right]));
        while (badCount > k) {
          badCount -= (bads.count(s[left]));
          left++;
        }
        count += (right - left + 1);
      }
      return count;
    };
    return sol(k) - sol(k - 1);
  }
};

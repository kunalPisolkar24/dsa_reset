#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> ump;
    int n = s.size();
    int left = 0, mx = 0;

    for (int right = 0; right < n; right++) {
      ump[s[right]]++;
      while (ump[s[right]] > 1) {
        ump[s[left]]--;
        if (ump[s[left]] == 0)
          ump.erase(s[left]);
        left++;
      }
      mx = max(mx, (int)ump.size());
    }
    return mx;
  }
};

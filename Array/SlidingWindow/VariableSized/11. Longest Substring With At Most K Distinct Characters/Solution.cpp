#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    int left = 0, n = s.size(), mx = 0;
    unordered_map<char, int> ump;
    if(k == 0) return 0;
    for (int right = 0; right < n; right++) {
      ump[s[right]]++;
      while (ump.size() > k) {
        ump[s[left]]--;
        if (ump[s[left]] == 0)
          ump.erase(s[left]);
        left++;
      }
      mx = max(mx, right - left + 1);
    }
    return mx;
  }
};

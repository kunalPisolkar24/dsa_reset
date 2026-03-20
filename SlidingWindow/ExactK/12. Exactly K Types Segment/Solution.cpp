#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int countSubstringsWithKDistinct(string s, int k) {
    int n = s.size();

    auto sol = [&](int k) -> int {
      unordered_map<char, int> ump;
      int left = 0, count = 0;
      for (int right = 0; right < n; right++) {
        ump[s[right]]++;
        while (ump.size() > k) {
          ump[s[left]]--;
          if (ump[s[left]] == 0) {
            ump.erase(s[left]);
          }
          left++;
        }
        count += (right - left + 1);
      }
      return count;
    };

    return sol(k) - sol(k - 1);
  }
};

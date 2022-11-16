#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  Solution() {}
  int lengthOfLongestSubstring(string s) {
    int l = 0, pl = 0;
    unordered_map<char, int> d;
    unordered_map<char, int>::iterator it;
    for (auto &&c : s) {
      if (c != ' ') {
        d[c]++;
        if (d[c] > 1) {
          // cout << "repeate found on " << c << " lenght was: "<<l<<"\n";
          if (pl < l) pl = l;  // store prev len
          l = 1;
          d.clear();
          d[c]++;
          // cout << "d[c]=" << d[c] << endl;
        } else
          l++;
      }
    }
    return pl;
  }
};
int main() {
  Solution leetcode;
  string s;
  cin >> s;
  cout << leetcode.lengthOfLongestSubstring(s);
  return 0;
}
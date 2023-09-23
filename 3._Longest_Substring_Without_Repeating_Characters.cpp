// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    Solution() {}
    int lengthOfLongestSubstring(string s) {
        int windowL = 0, windowR = 0, returnLength = 0, itr = 0;
        unordered_map<char, pair<int, int>> visitedStorage;
        for (char c : s) {
            visitedStorage[c] = make_pair(visitedStorage[c].first + 1, itr);
            if (visitedStorage[c].first > 1) {
                // repeat found.
                returnLength = max(returnLength, itr - windowL);
            }
            itr++;
        }
        return returnLength;
    }
};
int main() {
    Solution leetcode;
    string ip;
    cin >> ip;
    cout << leetcode.lengthOfLongestSubstring(ip);
    return 0;
}
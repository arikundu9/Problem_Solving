// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
using namespace std;
class Solution {
  private:
    list<char> visitedStorage;

  public:
    Solution() {}
    int lengthOfLongestSubstring(string s) {
        int windowL = 0, windowR = 0, returnLength = 0, itr = 0;
        for (char c : s) {
            visitedStorage.push_back(c);
            list<char>::iterator it =
                find(visitedStorage.begin(), visitedStorage.end(), c);
            if (it != visitedStorage.end()) {
                // repeat found.
                int diff = it - visitedStorage.begin();
                returnLength = max(returnLength, diff);
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
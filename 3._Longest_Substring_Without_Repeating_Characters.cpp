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
        int returnLength = 0;
        for (char c : s) {
            list<char>::iterator it =
                find(visitedStorage.begin(), visitedStorage.end(), c);
            if (it != visitedStorage.end()) {
                // repeat found.
                // cout<<"  [LOG]: c="<<c;
                // cout<<"  [LOG]: size="<<visitedStorage.size();
                // print();
                visitedStorage.erase(visitedStorage.begin(), ++it);
            }
            visitedStorage.push_back(c);

            returnLength = max(returnLength, int(visitedStorage.size()));
        }
        return returnLength;
    }
    void print() {
        cout << "  [PRINT] ";
        for (char c : visitedStorage) {
            cout << c << ", ";
        }
        cout << endl;
    }
};
int main() {
    Solution leetcode;
    string ip;
    cin >> ip;
    cout << leetcode.lengthOfLongestSubstring(ip);
    return 0;
}
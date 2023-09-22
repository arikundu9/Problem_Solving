// https://leetcode.com/problems/longest-common-prefix/
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    Solution() {}
    string longestCommonPrefix(vector<string> &strs) {
        string prefix;
        int horizontalItr = 0;
        bool outerLoopFlag = true, compAccumulator = true;
        while (outerLoopFlag) {
            compAccumulator = true;
            for (int verticalItr = 0; verticalItr < strs.size();
                 ++verticalItr) {
                if (strs[verticalItr].length() > 1) {
                    compAccumulator =
                        compAccumulator and (strs[verticalItr][horizontalItr] ==
                                             strs[0][horizontalItr]);
                    if (verticalItr == strs.size() - 1) { // last iteration
                        if (compAccumulator) {
                            prefix += strs[0][horizontalItr];
                        } else {
                            outerLoopFlag = false;
                            break;
                        }
                    }
                } else {
                    outerLoopFlag = false;
                    break;
                }
            }
            ++horizontalItr;
        }
        if (strs.size() == 1) {
            prefix = strs[0];
        }
        return prefix;
    }
};
int main() {
    Solution leetcode;
    vector<string> ip;
    string i;
    while (true) {
        cin >> i;
        if (i[0] >= 97 and i[0] <= 122) {
            ip.push_back(i);
        } else {
            break;
        }
    }
    cout << leetcode.longestCommonPrefix(ip);
    return 0;
}
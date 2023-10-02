// https://leetcode.com/problems/3sum/description/
#include <iostream>
#include <sstream>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
  private:
    vector<vector<int>> triplets;
    vector<int> nums;

  public:
    Solution() {}
    vector<vector<int>> threeSum(vector<int> &nums) {
        this->nums = nums;
        for (int i = 0; i < nums.size(); i++) {
            int remainingSum = 0 - nums[i];
            vector<vector<int>> r2s = twoSum(remainingSum, i);
            for (vector<int> &rC : r2s) {
                // cout << "for " << nums[i] << ",remaing=" << remainingSum
                //      << " rsum index are:" << rC[0] << "&" << rC[1] << endl;
                rC.push_back(i);
                triplets.push_back({nums[rC[0]], nums[rC[1]], nums[rC[2]]});
            }
        }
        return triplets;
    }

    vector<vector<int>> twoSum(int sum, int except_pos) {
        vector<vector<int>> rContainer;
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); ++i) {
            if (i != except_pos) {
                umap[nums[i]] = i;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            int rOperand = sum - nums[i];
            if (i != except_pos and (umap.find(rOperand) != umap.end())) {
                if (i != umap[rOperand]) {
                    // cout << "\tsum=" << sum << " & i=" << i
                    //      << " & num[i]=" << nums[i]
                    //      << " & umap.find=" << umap[rOperand] << endl;
                    rContainer.push_back({i, umap[rOperand]});
                }
            }
        }
        return rContainer;
    }

    friend ostream &operator<<(ostream &out, const Solution &dummy) {
        for (vector<int> v : dummy.triplets) {
            for (int x : v) {
                out << x << ",";
            }
            out << endl;
        }
        return out;
    }
};
int main() {
    Solution leetcode;
    vector<int> arg;
    string ip, buf;
    cin >> ip;
    stringstream ss(ip);
    while (getline(ss, buf, ',')) {
        arg.push_back(stoi(buf));
    }
    leetcode.threeSum(arg);
    cout << leetcode;
    return 0;
}
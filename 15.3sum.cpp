// https://leetcode.com/problems/3sum/description/
#include <iostream>
#include <sstream>
#include <tuple>
#include <vector>
using namespace std;
class Solution {
  private:
    vector<vector<int>> triplets;

  public:
    Solution() {}
    vector<vector<int>> threeSum(vector<int> &nums) { return triplets; }

    // tuple<int, int> twoSum(int sum, int except, vector<int> nums) {
        
    // }

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
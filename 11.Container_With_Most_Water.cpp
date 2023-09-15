//https://leetcode.com/problems/container-with-most-water/description/
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    Solution() {}
    int maxArea(vector<int>& height) {
        //Complexity: O(n^2)
        int a=0;
        for (int i = 0; i < height.size(); i++)
        {
            for (int j = 0; j < height.size(); j++)
            {
                if(j<i){
                    int newA = (i-j)*min(height[i],height[j]);
                    if(newA>a){
                        a = newA;
                    }
                }
            }
            
        }
        return a;
    }
};
int main() {
    Solution leetcode;
    vector<int> ip;
    int i;
    while(true){
        cin>>i;
        if(i>=0){
            ip.push_back(i);
        }
        else{
            break;
        }
    }
    cout<<leetcode.maxArea(ip);
    return 0;
}
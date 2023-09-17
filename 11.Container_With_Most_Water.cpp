//https://leetcode.com/problems/container-with-most-water/description/
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    Solution() {}
    int maxArea(vector<int>& h) {
        int i=0,j=h.size()-1, a=-1,n=-1;
        while (i<j)
        {
            n = min(h[i],h[j])*(j-i);
            if(n>a){
                a = n;
            }
            if(h[i]<h[j]){
                i++;
            }
            else{
                j--;
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
//https://leetcode.com/problems/container-with-most-water/description/
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    Solution() {}
    int maxArea(vector<int>& h) {
        //Complexity:
        int a=0;
        // cout<<"f="<<isHeightPrecedencedData(h);
        // cout<<"lastSecHeighest="<<lastSecHeighest<<endl;
        // if(isHeightPrecedencedData(h)){
            int firstHeighest = posOf1st(heighest(h),h);
            int lastHeighest = posOfLast(heighest(h),h);
            int firstSecHeighest = posOf1st(secondHeighest(h),h);
            int lastSecHeighest = posOfLast(secondHeighest(h),h);
            if((lastSecHeighest - firstHeighest) >= (lastHeighest - firstSecHeighest)){
                a = (lastSecHeighest - firstHeighest)*secondHeighest(h);
            }
            else{
                a = (lastHeighest - firstSecHeighest)*secondHeighest(h);
            }
        // }
        return a;
    }

    bool isHeightPrecedencedData(vector<int>& h){
        return h.size() <= secondHeighest(h);
    }

    int heighest(vector<int>& h){
        int m = 0;
        for(int x : h){
            m = x > m ? x : m;
        }
        return m;
    }

    int secondHeighest(vector<int>& h){
        int m = heighest(h) , sM = -1;
        for(int x : h){
            sM = x > sM and x < m ? x : sM;
        }
        return sM==-1 ? m : sM;
    }

    int posOf1st(int v,vector<int>& h){
        int p=-1;
        for(int i=0; i < h.size(); ++i){
            if(h[i]==v){
                p=i;
                break;
            }
        }
        return p;
    }
    int posOfLast(int v,vector<int>& h){
        int p=-1;
        for(int i=h.size() -1; i >= 0; --i){
            if(h[i]==v){
                p=i;
                break;
            }
        }
        return p;
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
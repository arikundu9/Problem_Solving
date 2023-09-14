#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    Solution() {}
    string convert(string s,int numRows) {
        string r;
        for(int k=0; k<numRows; k++){
            for(int i=0; i<s.length(); i=i+numRows+2){
                if(k==0){
                    r+=s[i];
                }
                else{
                    if(i-k>0 and i-k<s.length()-1){
                        r+=s[i-k];
                    }
                    if(i+k>0 and i+k<s.length()-1){
                        r+=s[i+k];
                    }
                }
            }
        }
        return r;
    }
};
int main() {
    Solution leetcode;
    string ip;
    int numRows;
    cin >> ip;
    cin >> numRows;
    cout<<leetcode.convert(ip,numRows);
    return 0;
}
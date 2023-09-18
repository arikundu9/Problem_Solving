
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        for(string x : strs){
            cout<<x<<endl;
        }
        return prefix ;
    }
};
    
int main(){
    Solution leetcode;
    vector<string> ip;
    string i;
    while(true){
        cin>>i;
        if(i[0]>=97 and i[0]<=122){
            ip.push_back(i);
        }
        else{
            break;
        }
    }
    cout<<leetcode.longestCommonPrefix(ip);
    return 0;
}

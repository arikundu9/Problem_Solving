//https://leetcode.com/problems/zigzag-conversion/description/
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    Solution() {}
    string convert(string s,int numRows) {
        string r;
        for(int k=0; k<numRows; k++){
            for(int i=0; i<s.length(); i=i+numRows+(numRows%2==0 ? 2 : 1)){
                if(k==0){
                    r+=s[i];
                    cout << "[*] i="<<i<<" and k="<<k<<" v="<<s[i]<<endl;
                }
                else{
                    if(i-k>0){
                        r+=s[i-k];
                        cout << "[+] i="<<i<<" and k="<<k<<" v="<<s[i-k]<<endl;
                    }
                    if(i+k<=s.length()-1){
                        r+=s[i+k];
                        cout << "[-] i="<<i<<" and k="<<k<<" v="<<s[i+k]<<endl;
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
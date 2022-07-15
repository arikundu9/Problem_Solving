#include <bits/stdc++.h>
using namespace std;



class Solution {
 public:
  Solution() {}
  int romanToInt(string s) {
    int r=0;
    for (int cur_pos = 0; cur_pos < s.length(); cur_pos++) {
        if(cur_pos!=s.length()-1){
            if(val(s.at(cur_pos))<val(s.at(cur_pos+1))){
              r=r-val(s.at(cur_pos));
            }
            else{
              r=r+val(s.at(cur_pos));
            }
        }
        else{
          r=r+val(s.at(cur_pos));
        }
    }
    return r;
  }
  int val(char c) {
  int r;
  switch (c) {
    case 'I':
      r = 1;
      break;
    case 'V':
      r = 5;
      break;
    case 'X':
      r = 10;
      break;
    case 'L':
      r = 50;
      break;
    case 'C':
      r = 100;
      break;
    case 'D':
      r = 500;
      break;
    case 'M':
      r = 1000;
      break;
  }
  return r;
}
};
int main() {
  Solution leetcode;
  string ip;
  cin >> ip;
  cout<<leetcode.romanToInt(ip);
  return 0;
}
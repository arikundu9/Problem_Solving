#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
    long int cpx=x,ld,nn=0;
    while(x){
        ld=x%10;
        // cout<<ld<<endl;
        x/=10;
        nn=nn*10+ld;
    }
    // cout<<"nn="<<nn<<endl;
    return (nn==cpx)and(cpx>=0);
}

int main(){
    int x;
    cin>>x;
    cout<<isPalindrome(x);
    return 0;
}
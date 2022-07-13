#include<iostream>
using namespace std;

void ff(int n,bool f){
    int x;
    if(n){
        cin>>x;
        ff(n-1,false);
        if(f)
        cout<<x<<endl;
        else
        cout<<x<<" ";
    }
}
int main(){
	int T=0,n;
	cin>>T;
	while(T!=0){
	    cin>>n;
	    ff(n,true);
	    T--;
	}
	return 0;
}
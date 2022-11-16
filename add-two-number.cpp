#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void addval(ListNode *l,int val){
    while(l->next!=nullptr)
        l=l->next;
    l->next = new ListNode(val);

}
void printl(ListNode *l){
    while(l!=nullptr){
        cout<<l->val;
        l=l->next;
    }
    // cout<<endl;
}
class Solution {
    public:
        Solution(){}
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode *r=new ListNode();
            ListNode *rr=r;
            int c=0,a;
            while(1){
                if(l1!=nullptr and l2!=nullptr){
                    a=l1->val+l2->val+c;
                    l1=l1->next;
                    l2=l2->next;
                }
                else if(l1==nullptr and l2!=nullptr){
                    a=l2->val+c;
                    l2=l2->next;
                }
                else if(l2==nullptr and l1!=nullptr){
                    a=l1->val+c;
                    l1=l1->next;
                }
                else if(c!=0){
                    a=c;
                }
                else{
                    break;
                }
                c=0;
                if(a>9){
                    a%=10;
                    c=1;
                } 
                // cout<<"carry:"<<c<<" sum:"<<a<<endl;
                r->next=new ListNode(a);
                r=r->next;
            }
            return rr->next;
        }
};
int main(){
    Solution leetcode;
    string s1,s2;
    cin>>s1>>s2;
    ListNode *l1,*l2;
    l1=new ListNode();
    l2=new ListNode();
    for (auto &&c : s1)
    {
        addval(l1,int(c)-48);
    }
    for (auto &&d : s2)
    {
        addval(l2,int(d)-48);
    }
    printl(leetcode.addTwoNumbers(l1->next,l2->next));
    return 0;
}
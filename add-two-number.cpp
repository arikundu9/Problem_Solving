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
        cout<<l->val<<",";
        l=l->next;
    }
    cout<<endl;
}
class Solution {
    public:
        Solution(){}
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            
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
    cout<<leetcode.addTwoNumbers(l1->next,l2->next);
    return 0;
}
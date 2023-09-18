
#include <bits/stdc++.h>
using namespace std;
class node {
  private:
    multimap<char, node *> childs;

  public:
    node() {}
    void insert(string str) {
        // cout<<"[+] insert(str)"<<str<<endl;
        if (str.length() == 1) {
            childs.insert(pair<char, node *>(str[0], nullptr));
        } else if (str.length() > 1) {
            node *newNode = new node();
            newNode->insert(str.substr(1, str.length() - 1));
            childs.insert(pair<char, node *>(str[0], newNode));
        }
    }
    void print(string ind = "\t") {
        int i=0;
        cout<<"\n[+] print()"<<endl;
        multimap<char, node *>::iterator itr;
        for (itr = childs.begin(); itr != childs.end(); ++itr) {
            cout <<"{"<<i<<"}"<< ind << itr->first;
            // cout << ind + "\t" << itr->second->childs.size();
            // itr->second->print(to_string(i*10+1)+ind + "\t");
            cout << endl;
            ++i;
        }
        cout << endl;
        return ;
    }
};
// class node{
//     private:
//         map<char,node*> leftChild;
//         map<char,node*> rightChild;
//     public:
//         node(){}
//         void insert(string str){
//             if (str.length() == 2) {

//             }
//             else if(str.length()>2){}
//         }
// };
class binaryTrie {};
class Solution {
    vector<string> strs;

  public:
    Solution() {}
    string longestCommonPrefix(vector<string> &strs) {
        this->strs = strs;
        node *start = new node();
        string prefix = "";
        for (string x : strs) {
            start->insert(x);
            // cout << x << endl;
        }
        start->print();
        return prefix;
    }
};

int main() {
    Solution leetcode;
    vector<string> ip;
    string i;
    while (true) {
        cin >> i;
        if (i[0] >= 97 and i[0] <= 122) {
            ip.push_back(i);
        } else {
            break;
        }
    }
    cout << leetcode.longestCommonPrefix(ip);
    return 0;
}

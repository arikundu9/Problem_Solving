
#include <bits/stdc++.h>
using namespace std;
class node {
  private:
    multimap<char, node *> childs;

  public:
    node() {}
    void insert(string str) {
        if (str.length() == 2) {
            childs.insert(pair<char, node *>(str[0], nullptr));
        } else if (str.length() > 2) {
            node *newNode = new node();
            newNode->insert(str.substr(1, str.length() - 1));
            childs.insert(pair<char, node *>(str[0], newNode));
        }
    }
    void print(string ind = "\t") {
        multimap<char, node *>::iterator itr;
        cout << "\tKEY\tELEMENT\n";
        for (itr = childs.begin(); itr != childs.end(); ++itr) {
            cout << ind << itr->first;
            itr->second->print(ind + "\t");
            cout << endl;
        }
        cout << endl;
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


#include <bits/stdc++.h>
using namespace std;
class node {
  private:
    char data;
    vector<node *> childs;

  public:
    node() { data = '\0'; }
    node(char c) { data = c; }

    void insertChild(string str) {
        if (str.length() == 1) {
            node *newNode = findOrGetNew(str[0]);
        } else if (str.length() > 1) {
            node *newNode = findOrGetNew(str[0]);
            newNode->insertChild(str.substr(1, str.length() - 1));
        }
    }

    node *findOrGetNew(char c) {
        for (node *n : childs) {
            if (n->data == c) {
                return n;
            }
        }
        node *p = new node(c);
        childs.push_back(p);
        return p;
    }

    void print(string ind = "\t|") {
        cout << ind + "[+] " << data << endl;
        for (node *n : childs) {
            n->print(ind + "\t|");
        }
    }

    string getPrifix() {
        string prefix;
        if (childs.size() == 1) {
            if (data != '\0') {
                prefix = data + childs[0]->getPrifix();
            } else {
                prefix = childs[0]->getPrifix();
            }
        } else {
            if (data != '\0') {
                prefix = data;
            }
        }
        return prefix;
    }
};
class binaryTrie {};
class Solution {
    vector<string> strs;

  public:
    Solution() {}
    string longestCommonPrefix(vector<string> &strs) {
        this->strs = strs;
        node *start = new node();
        for (string x : strs) {
            start->insertChild(x);
            // cout << x << endl;
        }
        // start->print();
        return start->getPrifix();
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

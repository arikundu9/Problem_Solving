//https://leetcode.com/problems/longest-common-prefix/submissions/1053186692/
#include <bits/stdc++.h>
using namespace std;
class node {
  private:
    char data;
    vector<node *> childs;
    bool isEnd = false;

  public:
    node() { data = '\0'; }
    node(char c) { data = c; }

    void insertChild(string str) {
        if (str.length() <= 1) {
            node *newNode = findOrGetNew(str[0]);
            newNode->isEnd = true;
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

    void print(string ind = "|") {
        cout << ind + "[+] " << data << (isEnd ? "[END]" : "") << endl;
        for (node *n : childs) {
            n->print(ind + "\t|");
        }
    }

    string getPrifix(bool previousFlag = false) {
        string prefix = "";
        if (childs.size() == 1) {
            if (!previousFlag) {
                if (data != '\0') {
                    prefix = data + childs[0]->getPrifix(isEnd);
                } else {
                    prefix = childs[0]->getPrifix(isEnd);
                }
            }
        } else {
            if (!previousFlag and data != '\0') {
                prefix = data;
            }
        }
        return prefix;
    }
};

class Solution {

  public:
    Solution() {}
    string longestCommonPrefix(vector<string> &strs) {
        string prefix;
        node *start = new node();
        for (string x : strs) {
            start->insertChild(x);
            // cout <<"[x]"<< x << endl;
        }
        // start->print();
        prefix = start->getPrifix();
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
            // cout<<"[--] "<<i<<endl;
        } else {
            break;
        }
    }

    // ip.push_back("ab");
    // ip.push_back("a");
    // ip.push_back("flower");
    // ip.push_back("flow");
    // ip.push_back("flight");
    // cout << leetcode.longestCommonPrefix(ip);
    // string h = "fab";
    // cout<<h.length()<<endl;
    cout << leetcode.longestCommonPrefix(ip) << endl;
    return 0;
}

// Wrong Answer
// 102 / 124 testcases passed
// Editorial
// Input
// strs =
// ["ab", "a"]

// Use Testcase
// Output
// "ab"
// Expected
// "a"

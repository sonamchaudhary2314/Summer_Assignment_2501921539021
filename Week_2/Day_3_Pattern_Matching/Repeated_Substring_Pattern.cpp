#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        string doubled = s + s;

        string check = doubled.substr(1, doubled.length() - 2);

        return check.find(s) != string::npos;
    }
};

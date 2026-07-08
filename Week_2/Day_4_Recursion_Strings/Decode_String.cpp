#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {

        stack<int> countStack;
        stack<string> stringStack;

        string current = "";
        int num = 0;

        for (char ch : s) {

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            else if (ch == '[') {
                countStack.push(num);
                stringStack.push(current);

                num = 0;
                current = "";
            }

            else if (ch == ']') {

                string temp = current;

                current = stringStack.top();
                stringStack.pop();

                int repeat = countStack.top();
                countStack.pop();

                while (repeat--) {
                    current += temp;
                }
            }

            else {
                current += ch;
            }
        }

        return current;
    }
};

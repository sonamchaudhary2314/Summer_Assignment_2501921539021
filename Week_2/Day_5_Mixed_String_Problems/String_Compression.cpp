#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {

        int index = 0;
        int i = 0;

        while (i < chars.size()) {

            char current = chars[i];

            int count = 0;

            while (i < chars.size() && chars[i] == current) {
                count++;
                i++;
            }

            chars[index++] = current;

            if (count > 1) {

                string str = to_string(count);

                for (char ch : str) {
                    chars[index++] = ch;
                }
            }
        }

        return index;
    }
};

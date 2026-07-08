#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        if (p.length() > s.length())
            return ans;

        vector<int> freqP(26, 0);
        vector<int> freqS(26, 0);

        for (char ch : p) {
            freqP[ch - 'a']++;
        }

        int window = p.length();

        for (int i = 0; i < s.length(); i++) {

            freqS[s[i] - 'a']++;

            if (i >= window) {
                freqS[s[i - window] - 'a']--;
            }

            if (freqS == freqP) {
                ans.push_back(i - window + 1);
            }
        }

        return ans;
    }
};

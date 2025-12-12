

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> freq;
        for (char c : s) freq[c]++;

        int len = 0;
        bool odd = false;

        for (auto &p : freq) {
            if (p.second % 2 == 0) len += p.second;
            else {
                len += p.second - 1;
                odd = true;
            }
        }

        return odd ? len + 1 : len;
    }
};

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.size() < p.size()) return res;

        vector<int> pCount(26,0), sCount(26,0);
        for (char c : p) pCount[c-'a']++;

        for (int i = 0; i < s.size(); i++) {
            sCount[s[i]-'a']++;

            if (i >= p.size()) {
                sCount[s[i - p.size()] - 'a']--;
            }

            if (sCount == pCount) {
                res.push_back(i - p.size() + 1);
            }
        }
        return res;
    }
};
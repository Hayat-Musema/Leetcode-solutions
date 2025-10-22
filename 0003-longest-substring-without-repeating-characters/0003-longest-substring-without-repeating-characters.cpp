class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;
        int left = 0, ans = 0;
        for (int right = 0; right < s.size(); right++) {
            if (seen.count(s[right]) && seen[s[right]] >= left)
                left = seen[s[right]] + 1;
            seen[s[right]] = right;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
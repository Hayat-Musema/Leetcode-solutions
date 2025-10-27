class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);
        queue<pair<char, int>> q;  // store (char, index)

        // Count frequency and track order
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            q.push({s[i], i});
        }

        // Remove all repeated chars from front of queue
        while (!q.empty() && freq[q.front().first - 'a'] > 1) {
            q.pop();
        }

        return q.empty() ? -1 : q.front().second;
    }
};
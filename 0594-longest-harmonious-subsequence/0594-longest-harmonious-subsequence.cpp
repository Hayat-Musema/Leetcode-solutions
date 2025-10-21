class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> cnt;
        for (int x : nums) ++cnt[x];
        int ans = 0;
        for (auto &p : cnt) {
            int v = p.first;
            if (cnt.find(v + 1) != cnt.end())
                ans = max(ans, p.second + cnt[v + 1]);
        }
        return ans;
    }
};
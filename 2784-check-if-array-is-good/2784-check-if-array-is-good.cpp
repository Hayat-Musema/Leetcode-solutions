class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;

        vector<int> freq(201, 0);

        for (int x : nums) {
            freq[x]++;
        }

        // n must appear exactly twice
        if (freq[n] != 2)
            return false;

        // 1 to n-1 must appear exactly once
        for (int i = 1; i < n; i++) {
            if (freq[i] != 1)
                return false;
        }

        return true;
    }
};
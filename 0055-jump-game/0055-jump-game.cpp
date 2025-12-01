class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > reachable) return false;  // can't reach this index
            reachable = max(reachable, i + nums[i]);
        }

        return true;
    }
};

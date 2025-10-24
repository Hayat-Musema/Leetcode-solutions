class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, sum = 0, minLen = nums.size() + 1;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return (minLen <= nums.size()) ? minLen : 0;
    }
};
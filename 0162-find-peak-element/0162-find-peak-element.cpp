class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1])
                right = mid; // peak is on the left side
            else
                left = mid + 1; // peak is on the right side
        }
        return left; // or right (both are same here)
    }
};

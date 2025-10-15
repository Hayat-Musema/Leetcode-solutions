class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // built-in sort from <algorithm>
        return nums;
    }
};

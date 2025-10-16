class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int num : nums) freq[num]++;  // Step 1: count frequencies

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if(freq[a] == freq[b])
                return a > b;           // If freq same, larger number first
            return freq[a] < freq[b];   // Smaller freq first
        });

        return nums;
    }
};

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int r = 0;
        int maxKeep = 1;  // at least one element

        for (int l = 0; l < n; l++) {
            // Move r right while the balanced condition holds:
            // nums[r] <= nums[l] * k
            while (r < n && (long long)nums[r] <= (long long)nums[l] * k) {
                r++;
            }
            // Now [l, r) is a valid balanced segment
            maxKeep = max(maxKeep, r - l);
        }

        // Minimum removals = total length - longest balanced segment length
        return n - maxKeep;
    }
};
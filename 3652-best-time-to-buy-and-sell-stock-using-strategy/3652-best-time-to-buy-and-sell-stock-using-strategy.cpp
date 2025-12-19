class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        // base profit = sum of original strategy * price
        long long base = 0;
        for (int i = 0; i < n; i++) {
            base += 1LL * strategy[i] * prices[i];
        }

        // prefix sums for original strategy profits
        vector<long long> prefOriginal(n + 1, 0);
        // prefix sums for just prices
        vector<long long> prefPrice(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefOriginal[i + 1] = prefOriginal[i] + 1LL * strategy[i] * prices[i];
            prefPrice[i + 1] = prefPrice[i] + prices[i];
        }

        long long maxProfitGain = 0; // extra gain from best modification

        // Slide window of length k to try modification
        for (int i = 0; i + k <= n; i++) {
            int left = i;
            int right = i + k;

            // original profit of this segment
            long long origSegmentProfit = prefOriginal[right] - prefOriginal[left];

            // new profit if we apply modification:
            // first half (k/2) contributes 0
            // second half (k/2) contributes sum of prices
            long long modSegmentProfit = prefPrice[right] - prefPrice[left + k/2];

            long long delta = modSegmentProfit - origSegmentProfit;
            maxProfitGain = max(maxProfitGain, delta);
        }

        return base + maxProfitGain;
    }
};


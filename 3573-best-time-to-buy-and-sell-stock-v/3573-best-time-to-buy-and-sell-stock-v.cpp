#3573

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        // dp[i][j][0] = max profit ending at day i with ≤ j transactions and neutral
        // dp[i][j][1] = with ≤ j transactions and currently long
        // dp[i][j][2] = with ≤ j transactions and currently short
        vector<vector<vector<long long>>> dp(n, 
            vector<vector<long long>>(k+1, vector<long long>(3, LLONG_MIN)));

        // Initialize for 0 transactions: only neutral = 0
        for (int j = 0; j <= k; j++) 
            dp[0][j][0] = 0;

        // For j>=1, on day 0 we can start a long or a short
        for (int j = 1; j <= k; j++) {
            dp[0][j][1] = -prices[0];   // buy
            dp[0][j][2] = prices[0];    // short
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                // Stay neutral or close long/short
                dp[i][j][0] = dp[i-1][j][0];
                if (dp[i-1][j][1] != LLONG_MIN)
                    dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][1] + prices[i]);
                if (dp[i-1][j][2] != LLONG_MIN)
                    dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][2] - prices[i]);

                if (j > 0) {
                    // Continue long or start a new long
                    dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);
                    // Continue short or start a new short
                    dp[i][j][2] = max(dp[i-1][j][2], dp[i-1][j-1][0] + prices[i]);
                }
            }
        }

        // Neutral state on last day with ≤k transactions
        return dp[n-1][k][0];
    }
};

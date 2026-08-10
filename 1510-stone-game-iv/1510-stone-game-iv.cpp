constexpr int N=1e5+1;
uint8_t dp[N*80];
uint8_t ver=0;
class Solution {
public:
    static bool winnerSquareGame(int n) {
    //    memset(dp[ver], 0, n+1);// no need 
        for (int i=1; i<=n; i++) {
            for (int k=1; k*k<=i; k++) {
                if (dp[ver*N+i-k*k]==0) {
                    dp[ver*N+i]=1;
                    break;
                }
            }
        }
        return dp[(ver++)*N+n];
    }
};



auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
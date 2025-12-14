#2147

class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;
        long long ways = 1;
        int seatCount = 0;
        int plantsBetween = 0;

        for (char c : corridor) {
            if (c == 'S') {
                seatCount++;
                if (seatCount > 2 && seatCount % 2 == 1) {
                    ways = (ways * (plantsBetween + 1)) % MOD;
                    plantsBetween = 0;
                }
            } else if (seatCount >= 2 && seatCount % 2 == 0) {
                plantsBetween++;
            }
        }

        if (seatCount < 2 || seatCount % 2 != 0) return 0;
        return ways;
    }
};

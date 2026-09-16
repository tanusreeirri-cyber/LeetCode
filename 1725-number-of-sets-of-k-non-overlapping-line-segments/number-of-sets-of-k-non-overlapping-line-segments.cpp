class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;

        vector<long long> dp(n, 0);
        vector<long long> prefix(n, 0);

        // 0 segments: 1 way
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
        }

        for (int seg = 1; seg <= k; seg++) {
            vector<long long> ndp(n, 0);

            long long sum = 0;

            for (int i = 1; i < n; i++) {
                // dp[i-1] represents ways before starting
                // a new segment
                sum = (sum + dp[i - 1]) % MOD;

                // End the segment at i
                ndp[i] = (ndp[i - 1] + sum) % MOD;
            }

            dp = ndp;
        }

        return dp[n - 1];
    }
};
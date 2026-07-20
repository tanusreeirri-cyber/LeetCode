1class Solution {
2public:
3    static constexpr int MOD = 1e9 + 7;
4
5    int subsequencePairCount(vector<int>& nums) {
6        const int MAX = 200;
7
8        vector<vector<long long>> dp(MAX + 1, vector<long long>(MAX + 1, 0));
9        dp[0][0] = 1;
10
11        for (int x : nums) {
12            auto ndp = dp;
13
14            for (int g1 = 0; g1 <= MAX; g1++) {
15                for (int g2 = 0; g2 <= MAX; g2++) {
16                    if (dp[g1][g2] == 0) continue;
17
18                    long long cur = dp[g1][g2];
19
20                    // Put into seq1
21                    int ng1 = (g1 == 0) ? x : std::gcd(g1, x);
22                    ndp[ng1][g2] = (ndp[ng1][g2] + cur) % MOD;
23
24                    // Put into seq2
25                    int ng2 = (g2 == 0) ? x : std::gcd(g2, x);
26                    ndp[g1][ng2] = (ndp[g1][ng2] + cur) % MOD;
27                }
28            }
29
30            dp.swap(ndp);
31        }
32
33        long long ans = 0;
34        for (int g = 1; g <= MAX; g++) {
35            ans = (ans + dp[g][g]) % MOD;
36        }
37
38        return ans;
39    }
40};
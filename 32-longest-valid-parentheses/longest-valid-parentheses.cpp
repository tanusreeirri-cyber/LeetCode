class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), ans = 0;
        vector<int> dp(n, 0);

        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                int j = i - 1 - dp[i - 1];

                if (j >= 0 && s[j] == '(') {
                    dp[i] = dp[i - 1] + 2;
                    if (j - 1 >= 0)
                        dp[i] += dp[j - 1];

                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};

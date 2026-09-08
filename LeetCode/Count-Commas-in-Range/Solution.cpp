1class Solution {
2public:
3    long long countCommas(int n) {
4        long long ans = 0;
5
6        for (long long x = 1000; x <= n; x *= 1000) {
7            ans += n - x + 1;
8        }
9
10        return ans;
11    }
12};
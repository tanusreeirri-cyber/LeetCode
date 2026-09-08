1class Solution:
2    def distinctSubseqII(self, s: str) -> int:
3        MOD = 10**9 + 7
4        last = {}
5        dp = 1 
6        
7        for char in s:
8            prev_dp = dp
9            dp = (2 * dp - last.get(char, 0)) % MOD
10            last[char] = prev_dp
11            
12        return (dp - 1) % MOD
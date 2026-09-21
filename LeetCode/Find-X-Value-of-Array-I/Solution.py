1class Solution:
2    def resultArray(self, nums: list[int], k: int) -> list[int]:
3        result = [0] * k
4        dp = [0] * k
5        
6        for num in nums:
7            val = num % k
8            next_dp = [0] * k
9            
10            # Start a new subarray ending at current element
11            next_dp[val] += 1
12            
13            # Extend previous subarrays ending at previous element
14            for rem in range(k):
15                if dp[rem] > 0:
16                    next_dp[(rem * val) % k] += dp[rem]
17            
18            dp = next_dp
19            
20            # Accumulate counts into the global result
21            for rem in range(k):
22                result[rem] += dp[rem]
23                
24        return result
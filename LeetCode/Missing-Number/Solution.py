1class Solution:
2    def missingNumber(self, nums: List[int]) -> int:
3        n=len(nums)
4        sum=int(n*(n+1)/2)
5        sum2=0
6        for i in range(n):
7            sum2+=nums[i]
8        return sum-sum2
9
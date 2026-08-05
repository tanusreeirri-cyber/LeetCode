class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n=len(nums)
        sum=int(n*(n+1)/2)
        sum2=0
        for i in range(n):
            sum2+=nums[i]
        return sum-sum2

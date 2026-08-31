1class Solution(object):
2    def majorityElement(self, nums):
3        freq=1
4        ans=nums[0]
5        for i in range(len(nums)):
6            if nums[i]==ans:
7                freq+=1
8            else:
9                freq-=1
10            if freq==0:
11                ans=nums[i]
12                freq=1
13        return ans
14        
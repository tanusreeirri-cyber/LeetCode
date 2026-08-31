1class Solution(object):
2    def majorityElement(self, nums):
3        """
4        :type nums: List[int]
5        :rtype: int
6        """
7        freq=1
8        ans=nums[0]
9        n=len(nums)
10        for i in range(n):
11            if nums[i]==ans:
12                freq+=1
13            else:
14                freq-=1
15            if freq==0:
16                ans=nums[i]
17                freq+=1
18        return ans
19        
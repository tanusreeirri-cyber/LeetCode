class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        freq=1
        ans=nums[0]
        n=len(nums)
        for i in range(n):
            if nums[i]==ans:
                freq+=1
            else:
                freq-=1
            if freq==0:
                ans=nums[i]
                freq=1
        return ans
        
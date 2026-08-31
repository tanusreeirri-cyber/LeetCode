class Solution(object):
    def majorityElement(self, nums):
        freq=1
        ans=nums[0]
        for i in range(len(nums)):
            if nums[i]==ans:
                freq+=1
            else:
                freq-=1
            if freq==0:
                ans=nums[i]
                freq=1
        return ans
        
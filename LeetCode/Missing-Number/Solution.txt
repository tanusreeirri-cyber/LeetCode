1class Solution {
2public:
3    int missingNumber(vector<int>& nums) {
4    int ans=nums.size();
5    for(int i=0;i<nums.size();i++){
6        ans^=i;
7        ans^=nums[i];
8    }
9    return ans;
10    }
11};
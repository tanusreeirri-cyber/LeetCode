1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4       int firstlarge=nums[0];
5       int seclarge=INT_MIN;
6        for(int i=1;i<nums.size();i++){
7            if(nums[i]>firstlarge){
8                seclarge=firstlarge;
9                firstlarge=nums[i];
10            }else if(nums[i]>seclarge){
11                seclarge=nums[i];
12            }
13        }
14        return (firstlarge-1)*(seclarge-1);
15    }
16};
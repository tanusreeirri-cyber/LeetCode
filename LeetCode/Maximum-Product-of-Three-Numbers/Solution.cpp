1class Solution {
2public:
3    int maximumProduct(vector<int>& nums){
4       sort(nums.begin(),nums.end());
5       int n=nums.size();
6       return max(nums[n-1]*nums[n-2]*nums[n-3],nums[0]*nums[1]*nums[n-1]);
7    }
8};
1class Solution {
2public:
3    int findGCD(vector<int>& nums) {
4       sort(nums.begin(),nums.end());
5       int n=nums.size()-1;
6       return gcd(nums[0],nums[n]); 
7    }
8};
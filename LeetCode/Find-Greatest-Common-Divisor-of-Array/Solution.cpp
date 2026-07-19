1class Solution {
2public:
3    int findGCD(vector<int>& nums) {
4       int n=nums.size()-1;
5       int max=nums[0];
6       int min=nums[0];
7       for(int i=0;i<=n;i++){
8        if(nums[i]>max){
9            max=nums[i];
10        }
11        if(nums[i]<min){
12            min=nums[i];
13        }
14       }
15       return gcd(min,max); 
16    }
17};
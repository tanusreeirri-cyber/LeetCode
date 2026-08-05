1class Solution {
2public:
3    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
4        vector<int>ans(nums.size());
5        for(int i=0;i<nums.size();i++){
6            int count=0;
7            for(int j=0;j<nums.size();j++){
8                if(nums[j]<nums[i]){
9                    count++;
10                }
11            }
12            ans[i]=count;
13        }
14        return ans;
15    }
16};
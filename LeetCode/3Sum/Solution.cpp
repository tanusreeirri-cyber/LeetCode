1class Solution {
2public:
3    vector<vector<int>> threeSum(vector<int>& nums) {
4     vector<vector<int>>ans;
5     sort(nums.begin(),nums.end());
6        for(int i=0;i<nums.size();i++){
7            if(i>0&&nums[i]==nums[i-1]) continue;
8            int j=i+1,k=nums.size()-1;
9            while(j<k){
10                int sum=nums[i]+nums[j]+nums[k];
11                if(sum<0){
12                    j++;
13                }
14                else if(sum>0){
15                    k--;
16                }else{
17                    ans.push_back({nums[i],nums[j],nums[k]});
18                    j++;
19                    k--;
20                    while(j<k&&nums[j]==nums[j-1]) j++;
21                }
22            }
23        }
24        return ans; 
25    }
26};
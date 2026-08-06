1class Solution {
2public:
3    vector<vector<int>> threeSum(vector<int>& nums) {
4        vector<vector<int>>ans;
5        sort(nums.begin(),nums.end());
6    for(int i=0;i<nums.size();i++){
7        if(i>0 && nums[i]==nums[i-1]) continue;
8        int j=i+1;
9        int k=nums.size()-1;
10        while(j<k){
11            int sum=nums[i]+nums[j]+nums[k];
12            if(sum>0){
13                k--;
14            }else if(sum<0){
15                j++;
16            }
17            else {
18                ans.push_back({nums[i],nums[j],nums[k]});
19                j++;
20                k--;
21                while(j<k&&nums[j]==nums[j-1]) j++; 
22            }
23        }
24    }
25    return ans;   
26    }
27};
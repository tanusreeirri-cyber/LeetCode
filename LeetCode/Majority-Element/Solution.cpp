1class Solution {
2public:
3    int majorityElement(vector<int>& nums) {
4      int freq=1;
5      int ans=nums[0];
6      for(int i=1;i<nums.size();i++){
7        if(nums[i]==ans){
8            freq++;
9        }else{
10            freq--;
11        }
12        if(freq==0){
13            ans=nums[i];
14            freq=1;
15        }
16      }
17      return ans;  
18    }
19};
1class Solution {
2public:
3    vector<int> productExceptSelf(vector<int>& nums) {
4        int n=nums.size();
5        vector<int>ans(nums.size());
6        ans[0]=1;
7        int suffix=1;
8        for(int i=1;i<n;i++){
9           ans[i]=ans[i-1]*nums[i-1];
10        }
11        for(int i=n-2;i>=0;i--){
12            suffix=suffix*nums[i+1];
13            ans[i]=ans[i]*suffix;
14        }
15        return ans;
16    }
17};
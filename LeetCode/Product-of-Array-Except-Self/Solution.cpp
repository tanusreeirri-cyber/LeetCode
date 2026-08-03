1class Solution {
2public:
3    vector<int> productExceptSelf(vector<int>& nums) {
4        int n=nums.size();
5        vector<int>ans(nums.size());
6        vector<int>prefix(nums.size());
7        vector<int>suffix(nums.size());
8        prefix[0]=1;
9        suffix[n-1]=1;
10        for(int i=1;i<n;i++){
11            prefix[i]=prefix[i-1]*nums[i-1];
12        }
13        for(int i=n-2;i>=0;i--){
14            suffix[i]=suffix[i+1]*nums[i+1];
15        }
16        for(int i=0;i<n;i++){
17            ans[i]=prefix[i]*suffix[i];
18        }
19        return ans;
20    }
21};
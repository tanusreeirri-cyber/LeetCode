1class Solution {
2public:
3    vector<vector<int>> fourSum(vector<int>& nums, int target) {
4       vector<vector<int>>ans;
5       int n=nums.size();
6       sort(nums.begin(),nums.end());
7       for(int i=0;i<n;i++){
8        if(i>0&&nums[i]==nums[i-1]) continue;
9        for(int j=i+1;j<n;){
10            int p=j+1,q=n-1;
11            while(p<q){
12                long long sum=(long long)nums[i]+(long long)nums[j]+(long long)nums[p]+(long long)nums[q];
13                if(sum<target){
14                    p++;
15                }else if(sum>target){
16                    q--;
17                }
18                else{
19                    ans.push_back({nums[i],nums[j],nums[p],nums[q]});
20                    p++;
21                    q--;
22                    while(p<q&&nums[p]==nums[p-1]) p++;
23                }
24            }
25            j++;
26            while(j<n&&nums[j]==nums[j-1]) j++;
27        }
28       }
29       return ans; 
30    }
31};
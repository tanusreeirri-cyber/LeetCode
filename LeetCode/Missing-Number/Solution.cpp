1class Solution {
2public:
3    int missingNumber(vector<int>& nums) {
4        int n=nums.size();
5        for(int i=0;i<=n;i++){
6            int flag=0;
7            for(int j=0;j<n;j++){
8                if(nums[j]==i){
9                    flag=1;
10                    break;
11                }
12            }
13            if(flag==0){
14                    return i;
15                }
16        }
17        return -1;
18    }
19};
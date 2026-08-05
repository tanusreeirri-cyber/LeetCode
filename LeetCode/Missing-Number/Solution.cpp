1class Solution {
2public:
3    int missingNumber(vector<int>& nums) {
4        int n=nums.size();
5       int sum=(n*(n+1))/2;
6       int s2=0;
7       for(int vals:nums){
8        s2+=vals;
9       }
10       return sum-s2;
11    }
12};
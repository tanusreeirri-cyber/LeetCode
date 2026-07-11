1class Solution {
2public:
3    int maxSubArray(vector<int>& nums) {
4        int maxsum=INT_MIN;
5        int cursum=0;
6        for(int vals:nums){
7            cursum+=vals;
8            maxsum=max(maxsum,cursum);
9            if(cursum<0){
10                cursum=0;
11            }
12        }
13    return maxsum;
14    }
15};
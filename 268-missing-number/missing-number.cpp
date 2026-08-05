class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
       int sum=(n*(n+1))/2;
       int s2=0;
       for(int vals:nums){
        s2+=vals;
       }
       return sum-s2;
    }
};
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
       vector<int>prefixgcd; 
       int currmax=0;
       for(int i=0;i<nums.size();i++){
        currmax=max(nums[i],currmax);
        prefixgcd.push_back(gcd(nums[i],currmax));
       }
       sort(prefixgcd.begin(),prefixgcd.end());
       int lp=0;
       int rp=nums.size()-1;
       long long ans=0;
       while(lp<rp){
        ans+=gcd(prefixgcd[lp],prefixgcd[rp]);
        lp++;
        rp--;
       }
    return ans;    
    }
};
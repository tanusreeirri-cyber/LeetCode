1class Solution {
2public:
3    long long gcdSum(vector<int>& nums) {
4       vector<int>prefixgcd; 
5       int currmax=0;
6       for(int i=0;i<nums.size();i++){
7        currmax=max(nums[i],currmax);
8        prefixgcd.push_back(gcd(nums[i],currmax));
9       }
10       sort(prefixgcd.begin(),prefixgcd.end());
11       int lp=0;
12       int rp=nums.size()-1;
13       long long ans=0;
14       while(lp<rp){
15        ans+=gcd(prefixgcd[lp],prefixgcd[rp]);
16        lp++;
17        rp--;
18       }
19    return ans;    
20    }
21};
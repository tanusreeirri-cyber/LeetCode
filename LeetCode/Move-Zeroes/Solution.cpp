1class Solution {
2public:
3    void moveZeroes(vector<int>& nums) {
4      int i=0;
5      int j=0;
6      while(j<nums.size()){
7        if(nums[j]!=0){
8            swap(nums[i],nums[j]);
9            i++;
10            j++;
11        }
12        else{
13            j++;
14        }
15      }  
16    }
17};
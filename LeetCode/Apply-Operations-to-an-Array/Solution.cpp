1class Solution {
2public:
3    vector<int> applyOperations(vector<int>& nums) {
4        for(int i=0;i<nums.size()-1;i++){
5            if(nums[i]==nums[i+1]){
6                nums[i]=nums[i]*2;
7                nums[i+1]=0;
8            }
9            }
10            int k=0;
11            int j=0;
12        while(j<nums.size()){
13            if(nums[j]!=0){
14                swap(nums[k],nums[j]);
15                k++;
16                j++;
17            }
18            else{
19                j++;
20            }
21        }
22        return nums;
23    }
24};
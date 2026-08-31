1class Solution {
2public:
3    int singleNonDuplicate(vector<int>& nums) {
4      int i=0;
5      int j=nums.size()-1;
6      while(i<=j){
7        int mid=i+(j-i)/2;
8        if((mid==nums.size()-1||nums[mid]!=nums[mid+1])&&(mid==0||nums[mid]!=nums[mid-1])){
9            return nums[mid];
10        }else if(mid%2==0){//even case
11            if(nums[mid-1]==nums[mid]){
12                j=mid-1;
13            }else{
14                i=mid+1;
15            }
16        }
17        else{
18            if(nums[mid]==nums[mid-1]){
19                i=mid+1;
20            }else{
21                j=mid-1;
22            }
23        }
24      }
25      return -1;  
26    }
27};
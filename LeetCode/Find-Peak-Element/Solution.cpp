1class Solution {
2public:
3    int findPeakElement(vector<int>& nums) {
4      int st=0,end=nums.size()-1;
5      while(st<end){
6        int mid=st+(end-st)/2;
7        if(nums[mid]<nums[mid+1]){
8            st=mid+1;
9        }else {
10            end=mid;
11        }
12      }
13      return st;  
14    }
15};
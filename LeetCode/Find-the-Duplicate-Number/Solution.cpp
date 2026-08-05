1class Solution {
2public:
3    int findDuplicate(vector<int>& nums) {
4      unordered_set<int>s;
5      for(int vals:nums){
6        if(s.find(vals)!=s.end()){
7            return vals;
8            break;
9        }
10        s.insert(vals);
11      } 
12     return -1;  
13    }
14};
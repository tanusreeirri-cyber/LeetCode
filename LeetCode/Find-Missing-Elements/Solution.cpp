1class Solution {
2public:
3    vector<int> findMissingElements(vector<int>& nums) {
4    vector<int>ans;
5    int min=INT_MAX;
6    int max=INT_MIN;
7    for(int i=0;i<nums.size();i++){
8        if(nums[i]>max){
9            max=nums[i];
10        }
11        if(nums[i]<min){
12            min=nums[i];
13        }
14    }
15    unordered_set<int>s;
16    for(int el:nums){
17        s.insert(el);
18    }
19    for(int i=min;i<=max;i++){
20        if(s.find(i)==s.end()){
21            ans.push_back(i);
22        }
23    }
24    return ans;
25    }
26};
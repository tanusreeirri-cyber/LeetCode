class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
    vector<int>ans;
    int min=INT_MAX;
    int max=INT_MIN;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>max){
            max=nums[i];
        }
        if(nums[i]<min){
            min=nums[i];
        }
    }
    unordered_set<int>s;
    for(int el:nums){
        s.insert(el);
    }
    for(int i=min;i<=max;i++){
        if(s.find(i)==s.end()){
            ans.push_back(i);
        }
    }
    return ans;
    }
};
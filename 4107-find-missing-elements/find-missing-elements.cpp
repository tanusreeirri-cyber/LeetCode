class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
    vector<int>ans;
    int mini=INT_MAX;
    int maxi=INT_MIN;
    for(int i=0;i<nums.size();i++){
        mini=min(mini,nums[i]);
        maxi=max(maxi,nums[i]);
    }
    unordered_set<int>s;
    for(int el:nums){
        s.insert(el);
    }
    for(int i=mini;i<=maxi;i++){
        if(s.find(i)==s.end()){
            ans.push_back(i);
        }
    }
    return ans;
    }
};
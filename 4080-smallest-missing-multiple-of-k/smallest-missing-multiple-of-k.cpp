class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
    unordered_set<int>s(nums.begin(),nums.end());
    int multiple=k;
    while(s.find(multiple)!=s.end()){
        multiple=multiple+k;
    }
    return multiple;
    }
};
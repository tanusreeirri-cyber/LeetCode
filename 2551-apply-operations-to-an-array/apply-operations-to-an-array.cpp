class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]=nums[i]*2;
                nums[i+1]=0;
            }
            }
            int k=0;
            int j=0;
        while(j<nums.size()){
            if(nums[j]!=0){
                swap(nums[k],nums[j]);
                k++;
                j++;
            }
            else{
                j++;
            }
        }
        return nums;
    }
};
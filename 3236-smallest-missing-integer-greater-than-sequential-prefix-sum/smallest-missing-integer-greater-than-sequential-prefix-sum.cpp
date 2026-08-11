class Solution {
public:
    int missingInteger(vector<int>& nums) {
      unordered_set<int>s(nums.size());  
      int sum=nums[0];
      for(int i=1;i<nums.size();i++){
        if(nums[i]==nums[i-1]+1){
            sum+=nums[i];
        }else{
            break;
        }
      }
      for(int i=0;i<nums.size();i++){
    if(s.find(nums[i])==s.end()){
        s.insert(nums[i]);
    }
    }
      int x=sum;
      while(true){
    bool found=false;
    for(int i=0;i<nums.size();i++){
        if(s.find(x)!=s.end()){
            found=true;
            break;
        }
    }if(found){
        x++;
    }else{
        break;
    }
    }
      return x; 
    }
};
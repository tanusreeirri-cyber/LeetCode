class Solution {
public:
    bool judgeSquareSum(int c) {
      int a=0;
      int b=sqrt(c);
      while(a<=b){
         
        if((long long)a * a + (long long)b * b==c){
            return true;
        }else if((long long)a * a + (long long)b * b<c){
            a++;
        }else{
            b--;
        }
      }
      return false;  
    }
};
class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int prod=1;
            int cur=n;
            while(cur>0){
                int digit=cur%10;
                prod=prod*digit;
                cur=cur/10;
            }
            if(prod%t==0){
                return n;
            }
            n++;
        }
        return -1;
    }
};
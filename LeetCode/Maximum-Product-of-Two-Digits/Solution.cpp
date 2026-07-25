1class Solution {
2public:
3    int maxProduct(int n) {
4      int max1=0;
5      int max2=0;
6      while(n!=0){
7      int dig=n%10;
8        if(dig>=max1){
9            max2=max1;
10            max1=dig;
11        }else if(dig>max2){
12            max2=dig;
13        }
14      n=n/10;  
15    }
16    return max1*max2;
17    }
18};
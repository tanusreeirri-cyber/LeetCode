1class Solution {
2public:
3    bool judgeSquareSum(int c) {
4      int a=0;
5      int b=sqrt(c);
6      while(a<=b){
7         
8        if((long long)a * a + (long long)b * b==c){
9            return true;
10        }else if((long long)a * a + (long long)b * b<c){
11            a++;
12        }else{
13            b--;
14        }
15      }
16      return false;  
17    }
18};
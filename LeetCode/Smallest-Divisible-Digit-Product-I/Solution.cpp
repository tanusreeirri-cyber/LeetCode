1class Solution {
2public:
3    int smallestNumber(int n, int t) {
4        while(true){
5            int prod=1;
6            int cur=n;
7            while(cur>0){
8                int digit=cur%10;
9                prod=prod*digit;
10                cur=cur/10;
11            }
12            if(prod%t==0){
13                return n;
14            }
15            n++;
16        }
17        return -1;
18    }
19};
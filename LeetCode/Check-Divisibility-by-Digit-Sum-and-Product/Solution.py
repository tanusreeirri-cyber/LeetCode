1class Solution:
2    def checkDivisibility(self, n: int) -> bool:
3        x=n
4        sum=0
5        prod=1
6        while(x>0):
7            dig=x%10
8            sum+=dig
9            prod*=dig
10            x=x//10
11        return n%(sum+prod)==0
12       
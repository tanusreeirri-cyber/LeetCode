class Solution:
    def checkDivisibility(self, n: int) -> bool:
        x=n
        sum=0
        prod=1
        while(x>0):
            dig=x%10
            sum+=dig
            prod*=dig
            x=x//10
        return n%(sum+prod)==0
       
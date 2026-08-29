class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        f0=0
        f1=1
        a=0
        for i in range(n):
            a=f1+f0
            f0=f1
            f1=a
        return a
        
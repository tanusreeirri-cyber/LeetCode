1class Solution {
2    boolean dp[]=new boolean[100001];
3    public boolean winnerSquareGame(int n) {
4        if(n==0)
5            return false;
6        if(dp[n])
7            return dp[n];
8        for(int i=1;i*i<=n;i++){
9            if(winnerSquareGame(n-i*i)==false)
10                return dp[n]=true;
11        }
12        return dp[n]=false;
13    }
14}
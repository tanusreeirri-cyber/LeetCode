1class Solution {
2public:
3    int diagonalSum(vector<vector<int>>& mat) {
4       int n=mat.size();
5       int sum=0;
6       for(int i=0;i<n;i++){
7            sum+=mat[i][i];
8            if(i!=n-i-1){//checking for common element to ignore adding it to sum twice
9                sum+=mat[i][n-i-1];
10            }
11       }
12       return sum; 
13    }
14};
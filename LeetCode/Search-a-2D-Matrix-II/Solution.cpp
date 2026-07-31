1class Solution {
2public:
3    bool searchMatrix(vector<vector<int>>& matrix, int target) {
4        int m=matrix.size();
5        int n=matrix[0].size();
6        int r=0;
7        int c=n-1;
8        while(c>=0&&r<m){
9            if(target==matrix[r][c]){
10                return true;
11            }else if(target<matrix[r][c]){
12                c--;
13            }else{
14                r++;
15            }
16        }
17        return false;
18    }
19};
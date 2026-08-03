1class Solution {
2public:
3    vector<int> spiralOrder(vector<vector<int>>& matrix) {
4        vector<int>ans;
5        int m=matrix.size();//rows
6        int n=matrix[0].size();//cols
7        int strow=0;
8        int endrow=m-1;
9        int stcol=0;
10        int endcol=n-1;
11        while(strow<=endrow&&stcol<=endcol){
12            //for top
13            for(int i=stcol;i<=endcol;i++){
14                ans.push_back(matrix[strow][i]);
15            }
16             //for right
17            for(int i=strow+1;i<=endrow;i++){
18                ans.push_back(matrix[i][endcol]);
19            }
20             //for bottom
21            for(int i=endcol-1;i>=stcol;i--){
22                if(strow==endrow){//for odd no of matrix
23                    break;
24                }
25                ans.push_back(matrix[endrow][i]);
26            }
27             //for left
28            for(int i=endrow-1;i>=strow+1;i--){
29                if(stcol==endcol){//for odd no of matrix,not to overlap cols
30                    break;
31                }
32                ans.push_back(matrix[i][stcol]);
33            }
34            strow++;endrow--;stcol++;endcol--;
35        }
36        return ans;
37    }
38};
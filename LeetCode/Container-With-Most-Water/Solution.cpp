1class Solution {
2public:
3    int maxArea(vector<int>& height) {
4        int maxwater=0;
5        int lb=0;
6        int rb=height.size()-1;
7        while(lb<rb){
8            int h=min(height[lb],height[rb]);
9            int w=rb-lb;
10            int area=h*w;
11            maxwater=max(area,maxwater);
12            if(height[lb]<height[rb]){
13                lb++;
14            }
15                else{
16                    rb--;
17                }
18            }
19            return maxwater;
20    }
21};
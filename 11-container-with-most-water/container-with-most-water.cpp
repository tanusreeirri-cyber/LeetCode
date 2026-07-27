class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater=0;
        int lb=0;
        int rb=height.size()-1;
        while(lb<rb){
            int h=min(height[lb],height[rb]);
            int w=rb-lb;
            int area=h*w;
            maxwater=max(area,maxwater);
            if(height[lb]<height[rb]){
                lb++;
            }
                else{
                    rb--;
                }
            }
            return maxwater;
    }
};
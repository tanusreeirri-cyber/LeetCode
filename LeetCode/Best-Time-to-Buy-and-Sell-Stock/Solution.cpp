1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4      int mp=0;
5      int bb=prices[0];
6      for(int i=1;i<prices.size();i++){
7        bb=min(bb,prices[i]);
8        if(prices[i]>bb){
9            mp=max(mp,prices[i]-bb);
10        }
11        
12      }
13      return mp;  
14    }
15};
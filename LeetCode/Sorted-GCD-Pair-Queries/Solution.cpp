1class Solution {
2public:
3    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
4        int mx = *max_element(nums.begin(), nums.end());
5
6
7        vector<long long> freq(mx + 1, 0);
8        for (int x : nums)
9            freq[x]++;
10
11    
12        vector<long long> exactPairs(mx + 1, 0);
13
14    
15        for (int g = mx; g >= 1; g--) {
16
17        
18            long long cnt = 0;
19            for (int multiple = g; multiple <= mx; multiple += g)
20                cnt += freq[multiple];
21
22        
23            long long pairs = cnt * (cnt - 1) / 2;
24
25    
26            for (int multiple = 2 * g; multiple <= mx; multiple += g)
27                pairs -= exactPairs[multiple];
28
29            exactPairs[g] = pairs;
30        }
31
32        
33        vector<long long> prefix(mx + 1, 0);
34        for (int g = 1; g <= mx; g++)
35            prefix[g] = prefix[g - 1] + exactPairs[g];
36
37        vector<int> ans;
38
39        for (long long q : queries) {
40        
41            int g = upper_bound(prefix.begin(), prefix.end(), q) - prefix.begin();
42            ans.push_back(g);
43        }
44
45        return ans;
46    }
47};
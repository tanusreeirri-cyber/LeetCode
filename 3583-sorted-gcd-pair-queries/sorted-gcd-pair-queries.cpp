class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());


        vector<long long> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

    
        vector<long long> exactPairs(mx + 1, 0);

    
        for (int g = mx; g >= 1; g--) {

        
            long long cnt = 0;
            for (int multiple = g; multiple <= mx; multiple += g)
                cnt += freq[multiple];

        
            long long pairs = cnt * (cnt - 1) / 2;

    
            for (int multiple = 2 * g; multiple <= mx; multiple += g)
                pairs -= exactPairs[multiple];

            exactPairs[g] = pairs;
        }

        
        vector<long long> prefix(mx + 1, 0);
        for (int g = 1; g <= mx; g++)
            prefix[g] = prefix[g - 1] + exactPairs[g];

        vector<int> ans;

        for (long long q : queries) {
        
            int g = upper_bound(prefix.begin(), prefix.end(), q) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};
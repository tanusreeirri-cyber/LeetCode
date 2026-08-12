1class Solution {
2public:
3    int maxSubarrayLength(vector<int>& nums, int k) {
4        unordered_map<int, int> freq;
5        int left = 0;
6        int ans = 0;
7        for (int right = 0; right < nums.size(); right++) {
8            freq[nums[right]]++;
9            while (freq[nums[right]] > k) {
10                freq[nums[left]]--;
11                left++;
12            }
13            ans = max(ans, right - left + 1);
14        }
15        return ans;
16    }
17};
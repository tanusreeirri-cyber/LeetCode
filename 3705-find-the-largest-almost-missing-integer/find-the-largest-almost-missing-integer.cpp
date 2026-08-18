class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int n = nums.size();

        for (int start = 0; start <= n - k; start++) {
            unordered_set<int> st;

            for (int i = start; i < start + k; i++) {
                st.insert(nums[i]);
            }

            for (int x : st) {
                count[x]++;
            }
        }

        int ans = -1;

        for (auto [x, freq] : count) {
            if (freq == 1) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};

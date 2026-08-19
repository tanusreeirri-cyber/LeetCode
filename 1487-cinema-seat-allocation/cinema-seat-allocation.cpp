class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;

        for (auto& seat : reservedSeats) {
            rows[seat[0]] |= 1 << seat[1];
        }

        int left = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int middle = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int right = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        long long ans = 2LL * (n - rows.size());

        for (auto& [row, mask] : rows) {
            bool l = (mask & left) == 0;
            bool m = (mask & middle) == 0;
            bool r = (mask & right) == 0;

            if (l && r)
                ans += 2;
            else if (l || m || r)
                ans += 1;
        }

        return ans;
    }
};
1class Solution {
2public:
3    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
4        unordered_map<int, int> rows;
5
6        for (auto& seat : reservedSeats) {
7            rows[seat[0]] |= 1 << seat[1];
8        }
9
10        int left = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
11        int middle = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
12        int right = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);
13
14        long long ans = 2LL * (n - rows.size());
15
16        for (auto& [row, mask] : rows) {
17            bool l = (mask & left) == 0;
18            bool m = (mask & middle) == 0;
19            bool r = (mask & right) == 0;
20
21            if (l && r)
22                ans += 2;
23            else if (l || m || r)
24                ans += 1;
25        }
26
27        return ans;
28    }
29};
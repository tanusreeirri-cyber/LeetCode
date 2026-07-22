1class Solution {
2public:
3    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
4        int n = s.size();
5
6        vector<int> prefOnes(n + 1, 0);
7        for (int i = 0; i < n; i++)
8            prefOnes[i + 1] = prefOnes[i] + (s[i] == '1' ? 1 : 0);
9        int totalOnes = prefOnes[n];
10
11        // extract maximal runs of '1's
12        vector<int> starts, ends;
13        {
14            int i = 0;
15            while (i < n) {
16                if (s[i] == '1') {
17                    int j = i;
18                    while (j < n && s[j] == '1') j++;
19                    starts.push_back(i);
20                    ends.push_back(j - 1);
21                    i = j;
22                } else {
23                    i++;
24                }
25            }
26        }
27
28        int m = starts.size();
29        vector<int> z1s(m), z2e(m), fullLeft(m), fullRight(m), G(m);
30
31        for (int idx = 0; idx < m; idx++) {
32            z1s[idx] = (idx == 0) ? 0 : ends[idx - 1] + 1;
33            z2e[idx] = (idx == m - 1) ? (n - 1) : starts[idx + 1] - 1;
34            fullLeft[idx] = starts[idx] - z1s[idx];
35            fullRight[idx] = z2e[idx] - ends[idx];
36            G[idx] = fullLeft[idx] + fullRight[idx];
37        }
38
39        // Sparse table over G for range-max queries
40        vector<int> LOG(m + 1, 0);
41        for (int i = 2; i <= m; i++) LOG[i] = LOG[i / 2] + 1;
42        int K = (m > 0) ? (LOG[m] + 1) : 1;
43
44        vector<vector<int>> sparse(max(K, 1), vector<int>(max(m, 1), 0));
45        if (m > 0) {
46            for (int i = 0; i < m; i++) sparse[0][i] = G[i];
47            for (int k = 1; k < K; k++) {
48                int half = 1 << (k - 1);
49                int limit = m - (1 << k) + 1;
50                for (int i = 0; i < max(limit, 0); i++) {
51                    sparse[k][i] = max(sparse[k - 1][i], sparse[k - 1][i + half]);
52                }
53            }
54        }
55
56        auto rangeMaxG = [&](int l, int r) -> long long {
57            if (l > r) return LLONG_MIN;
58            int k = LOG[r - l + 1];
59            return max(sparse[k][l], sparse[k][r - (1 << k) + 1]);
60        };
61
62        int q = queries.size();
63        vector<int> ans(q);
64
65        for (int qi = 0; qi < q; qi++) {
66            int l = queries[qi][0], r = queries[qi][1];
67
68            if (m == 0) {
69                ans[qi] = totalOnes; // == 0 in this case
70                continue;
71            }
72
73            int lo = upper_bound(starts.begin(), starts.end(), l) - starts.begin();
74            int hi = (int)(lower_bound(ends.begin(), ends.end(), r) - ends.begin()) - 1;
75
76            if (lo > hi || lo >= m || hi < 0) {
77                ans[qi] = totalOnes; // no interior run -> no valid trade
78                continue;
79            }
80
81            long long maxGain;
82
83            if (lo == hi) {
84                int run = lo;
85                int Leftc = starts[run] - max(z1s[run], l);
86                int Rightc = min(z2e[run], r) - ends[run];
87                maxGain = Leftc + Rightc;
88            } else {
89                int Leftc_lo = starts[lo] - max(z1s[lo], l);
90                long long gain_lo = Leftc_lo + fullRight[lo];
91
92                int Rightc_hi = min(z2e[hi], r) - ends[hi];
93                long long gain_hi = fullLeft[hi] + Rightc_hi;
94
95                maxGain = max(gain_lo, gain_hi);
96
97                if (hi > lo + 1) {
98                    maxGain = max(maxGain, rangeMaxG(lo + 1, hi - 1));
99                }
100            }
101
102            ans[qi] = totalOnes + (int)max(0LL, maxGain);
103        }
104
105        return ans;
106    }
107};
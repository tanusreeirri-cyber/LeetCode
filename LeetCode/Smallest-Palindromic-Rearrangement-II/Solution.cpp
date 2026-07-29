1class Solution {
2public:
3    static const long long CAP = 1000001; // > max possible k (1e6)
4
5    long long combCapped(long long a, long long b) {
6        if (b < 0 || b > a) return 0;
7        b = min(b, a - b);
8        long long res = 1;
9        for (long long i = 1; i <= b; i++) {
10            res = res * (a - b + i) / i;
11            if (res >= CAP) return CAP;
12        }
13        return res;
14    }
15
16    long long permCountCapped(vector<int>& counts, int total) {
17        long long result = 1;
18        int remaining = total;
19        for (int c = 0; c < 26; c++) {
20            if (counts[c] == 0) continue;
21            long long cval = combCapped(remaining, counts[c]);
22            result *= cval;
23            remaining -= counts[c];
24            if (result >= CAP) return CAP;
25        }
26        return result;
27    }
28
29    string smallestPalindrome(string s, int k) {   // <-- renamed to match LeetCode's expected signature
30        int n = s.size();
31        vector<int> cnt(26, 0);
32        for (char ch : s) cnt[ch - 'a']++;
33
34        vector<int> half(26, 0);
35        int midChar = -1;
36        for (int c = 0; c < 26; c++) {
37            half[c] = cnt[c] / 2;
38            if (cnt[c] % 2 == 1) midChar = c;
39        }
40
41        int halfLen = n / 2;
42        long long kk = k;
43
44        long long total = permCountCapped(half, halfLen);
45        if (kk > total) return "";
46
47        string leftHalf;
48        leftHalf.reserve(halfLen);
49        vector<int> remCounts = half;
50        int remLen = halfLen;
51
52        for (int pos = 0; pos < halfLen; pos++) {
53            for (int c = 0; c < 26; c++) {
54                if (remCounts[c] == 0) continue;
55                remCounts[c]--;
56                long long cnt2 = permCountCapped(remCounts, remLen - 1);
57                if (kk <= cnt2) {
58                    leftHalf.push_back('a' + c);
59                    remLen--;
60                    break;
61                } else {
62                    kk -= cnt2;
63                    remCounts[c]++;
64                }
65            }
66        }
67
68        string result = leftHalf;
69        if (midChar != -1) result.push_back('a' + midChar);
70        for (int i = (int)leftHalf.size() - 1; i >= 0; i--) result.push_back(leftHalf[i]);
71
72        return result;
73    }
74};
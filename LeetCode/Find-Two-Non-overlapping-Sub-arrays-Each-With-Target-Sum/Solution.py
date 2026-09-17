1class Solution:
2    def minSumOfLengths(self, arr, target):
3        n = len(arr)
4        INF = 10**9
5
6        best = [INF] * n
7
8        prefix = 0
9        mp = {0: -1}
10
11        min_len = INF
12        ans = INF
13
14        for i in range(n):
15            prefix += arr[i]
16
17            if prefix - target in mp:
18                start = mp[prefix - target]
19                length = i - start
20
21                if start >= 0 and best[start] != INF:
22                    ans = min(ans, best[start] + length)
23
24                min_len = min(min_len, length)
25
26            if i == 0:
27                best[i] = min_len
28            else:
29                best[i] = min(best[i - 1], min_len)
30
31            mp[prefix] = i
32
33        return -1 if ans == INF else ans
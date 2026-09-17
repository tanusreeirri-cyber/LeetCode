class Solution:
    def minSumOfLengths(self, arr, target):
        n = len(arr)
        INF = 10**9

        best = [INF] * n

        prefix = 0
        mp = {0: -1}

        min_len = INF
        ans = INF

        for i in range(n):
            prefix += arr[i]

            if prefix - target in mp:
                start = mp[prefix - target]
                length = i - start

                if start >= 0 and best[start] != INF:
                    ans = min(ans, best[start] + length)

                min_len = min(min_len, length)

            if i == 0:
                best[i] = min_len
            else:
                best[i] = min(best[i - 1], min_len)

            mp[prefix] = i

        return -1 if ans == INF else ans
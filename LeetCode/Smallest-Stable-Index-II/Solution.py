1class Solution:
2    def firstStableIndex(self, nums: List[int], k: int) -> int:
3        n = len(nums)
4
5        # suffixMin[i] = minimum value from i to n-1
6        suffixMin = [0] * n
7        suffixMin[-1] = nums[-1]
8
9        for i in range(n - 2, -1, -1):
10            suffixMin[i] = min(nums[i], suffixMin[i + 1])
11
12        # Find the first stable index
13        prefixMax = nums[0]
14
15        for i in range(n):
16            prefixMax = max(prefixMax, nums[i])
17
18            if prefixMax - suffixMin[i] <= k:
19                return i
20
21        return -1
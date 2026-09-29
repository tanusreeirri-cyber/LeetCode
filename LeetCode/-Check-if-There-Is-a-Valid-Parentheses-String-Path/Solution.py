1class Solution:
2    def hasValidPath(self, grid):
3        m = len(grid)
4        n = len(grid[0])
5
6        # Path length must be even
7        if (m + n - 1) % 2 == 1:
8            return False
9
10        # Starting cell must be '('
11        if grid[0][0] == ')':
12            return False
13
14        # dp[i][j] = set of possible balances at (i, j)
15        dp = [[set() for _ in range(n)] for _ in range(m)]
16
17        dp[0][0].add(1)
18
19        for i in range(m):
20            for j in range(n):
21
22                for balance in list(dp[i][j]):
23
24                    # Move down
25                    if i + 1 < m:
26                        new_balance = balance + (
27                            1 if grid[i + 1][j] == '(' else -1
28                        )
29
30                        if new_balance >= 0:
31                            dp[i + 1][j].add(new_balance)
32
33                    # Move right
34                    if j + 1 < n:
35                        new_balance = balance + (
36                            1 if grid[i][j + 1] == '(' else -1
37                        )
38
39                        if new_balance >= 0:
40                            dp[i][j + 1].add(new_balance)
41
42        return 0 in dp[m - 1][n - 1]
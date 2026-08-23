1class Solution:
2    def sumGame(self, num: str) -> bool:
3        n = len(num)
4        half = n // 2
5        
6        sum1 = sum(int(c) for c in num[:half] if c != '?')
7        sum2 = sum(int(c) for c in num[half:] if c != '?')
8        
9        cnt1 = num[:half].count('?')
10        cnt2 = num[half:].count('?')
11        
12        diff = sum1 - sum2
13        cnt_diff = cnt1 - cnt2
14        
15        # If the total number of excess '?' is odd, Alice always wins
16        if cnt_diff % 2 != 0:
17            return True
18        
19        # Bob wins if the initial sum difference can be balanced by Bob's pairs (each pair adds 9)
20        return diff + (cnt_diff // 2) * 9 != 0
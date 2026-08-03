1class Solution(object):
2    def largestRectangleArea(self, heights):
3        """
4        :type heights: List[int]
5        :rtype: int
6        """
7        stack = [] # indices, increasing heights
8
9        best = 0
10
11        for i, h in enumerate(heights + [0]):
12
13            while stack and heights[stack[-1]] >= h:
14
15                height = heights[stack.pop()]
16
17                left = stack[-1] + 1 if stack else 0
18
19                width = i - left
20
21                best = max(best, height * width)
22
23            stack.append(i)
24
25        return best
26        
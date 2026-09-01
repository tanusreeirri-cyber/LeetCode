1from collections import deque
2from typing import List
3
4class Solution:
5    def minMoves(self, classroom: List[str], energy: int) -> int:
6        m, n = len(classroom), len(classroom[0])
7        
8        start_r = start_c = -1
9        litter_coords = {}
10        litter_count = 0
11        
12        # 1. Parse grid to locate 'S' and assign bit indices to each 'L'
13        for r in range(m):
14            for c in range(n):
15                if classroom[r][c] == 'S':
16                    start_r, start_c = r, c
17                elif classroom[r][c] == 'L':
18                    litter_coords[(r, c)] = litter_count
19                    litter_count += 1
20        
21        # If there's no litter from the start
22        if litter_count == 0:
23            return 0
24
25        # Initial mask: all litter bits set to 1
26        initial_mask = (1 << litter_count) - 1
27        
28        # BFS Queue holds tuples: (r, c, remaining_energy, bitmask)
29        queue = deque([(start_r, start_c, energy, initial_mask)])
30        
31        # Visited set tracks: (r, c, remaining_energy, bitmask)
32        visited = set([(start_r, start_c, energy, initial_mask)])
33        
34        moves = 0
35        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
36        
37        while queue:
38            for _ in range(len(queue)):
39                r, c, cur_energy, mask = queue.popleft()
40                
41                # Check if all litter items have been collected
42                if mask == 0:
43                    return moves
44                
45                # If energy is 0 and we are not on 'R', we cannot move further
46                if cur_energy == 0:
47                    continue
48                
49                # Explore 4 adjacent directions
50                for dr, dc in directions:
51                    nr, nc = r + dr, c + dc
52                    
53                    # Check boundary and obstacle conditions
54                    if 0 <= nr < m and 0 <= nc < n and classroom[nr][nc] != 'X':
55                        next_cell = classroom[nr][nc]
56                        next_energy = cur_energy - 1
57                        next_mask = mask
58                        
59                        # Handle Reset Area
60                        if next_cell == 'R':
61                            next_energy = energy
62                        
63                        # Handle Litter Collection
64                        elif next_cell == 'L' and (nr, nc) in litter_coords:
65                            bit = litter_coords[(nr, nc)]
66                            next_mask &= ~(1 << bit)
67                        
68                        state = (nr, nc, next_energy, next_mask)
69                        if state not in visited:
70                            visited.add(state)
71                            queue.append(state)
72            
73            moves += 1
74            
75        return -1
1class Solution {
2public:
3    int uniqueXorTriplets(vector<int>& nums) {
4        int n = nums.size();
5
6        if (n == 1) return 1;
7        if (n == 2) return 2;
8
9        int bits = 0;
10        int temp = n;
11        while (temp > 0) {
12            bits++;
13            temp >>= 1;
14        }
15
16        return 1 << bits;
17    }
18};
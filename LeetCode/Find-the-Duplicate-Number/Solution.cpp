1class Solution {
2public:
3    int findDuplicate(vector<int>& arr) {
4        int slow=arr[0],fast=arr[0];
5        do{
6            slow=arr[slow];
7            fast=arr[arr[fast]];
8        }while(slow!=fast);
9            slow=arr[0];
10            while(slow!=fast){
11                slow=arr[slow];
12                fast=arr[fast];
13            }
14        return slow;
15    }
16};
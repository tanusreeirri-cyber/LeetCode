1class Solution {
2public:
3    int countPrimes(int n) {
4        vector<bool>is_prime(n+1,true);
5        int count=0;
6        for(int i=2;i<n;i++){
7            if(is_prime[i]){
8                count++;
9            for(long long j=1LL*i*i;j<n;j+=i){
10                is_prime[j]=false;
11            }
12            }
13        }
14        return count;
15    }
16};
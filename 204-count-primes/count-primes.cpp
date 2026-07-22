class Solution {
public:
    int countPrimes(int n) {
     vector<bool>is_prime(n+1,true);
     int count=0;
    for(int i=2;i<n;i++){
        if (is_prime[i]==true){
        count++;
        for(long long j=1LL*i*i;j<n;j+=i){
            is_prime[j]=false;
        }
        }    
    }
    return count;    
    }
};
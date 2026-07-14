class Solution {
public:
    bool isSubsequence(string s, string t) {
       int l=0;
       int r=0;
       while(r<t.length()){
        if(s[l]==t[r]){
            l++;
            r++;
        }
        else{
            r++;
        }
       }
        if(l==s.length()){
            return true;
        }
        else{
            return false;
        }
       }
};
1class Solution {
2public:
3    bool isalphanum(char ch){
4        if((ch>='0' && ch<='9') ||( tolower(ch)>='a' && tolower(ch)<='z')){
5            return true;
6        }
7        return false;
8    }
9    bool isPalindrome(string s) {
10     int st=0;
11     int end=s.length()-1;
12     while(st<end){
13        if(!isalphanum(s[st])){
14            st++;
15            continue;
16        }
17        if(!isalphanum(s[end])){
18            end--;
19            continue;
20        }
21        if(tolower(s[st])!=tolower(s[end])){
22            return false;
23        }
24        st++;
25        end--;
26     } 
27    return true;  
28    }
29};
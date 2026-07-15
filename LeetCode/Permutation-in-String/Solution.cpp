1class Solution {
2public:
3    bool isfreqsame(int freq1[],int freq2[]){
4        for(int i=0;i<26;i++){
5            if(freq1[i]!=freq2[i]){
6                return false;
7            }
8        }
9        return true;
10    }
11    bool checkInclusion(string s1, string s2) {
12        int freq[26]={0};
13        for(int i=0;i<s1.length();i++){
14            freq[s1[i]-'a']++;
15        }
16        int windsize=s1.length();
17        for(int i=0;i<s2.length();i++){
18            int windidx=0;
19            int idx=i;
20            int windfreq[26]={0};
21            while(windidx<windsize && idx<s2.length()){
22                windfreq[s2[idx]-'a']++;
23                windidx++;
24                idx++;
25            }
26            if(isfreqsame(freq,windfreq)){
27                return true;
28            }
29        }
30        return false;
31    }
32};
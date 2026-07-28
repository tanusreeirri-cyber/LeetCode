class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }
        string firsthalf="";
        string middle="";
        for(int i=0;i<26;i++){
            firsthalf+=string(freq[i]/2,char('a'+i));
        if(freq[i]%2==1){
            middle=char('a'+i);
        }
        }
        string lasthalf=firsthalf;
        reverse(lasthalf.begin(),lasthalf.end());
        return firsthalf+middle+lasthalf;
    }
};
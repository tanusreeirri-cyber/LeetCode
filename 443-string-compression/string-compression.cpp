class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int idx=0;
        int i=0;
    while(i<n){
        char ch=chars[i];
        int count=0;
        while(i<n && chars[i]==ch){
            count++;
            i++;
        }
        if(count==1){
            chars[idx++]=ch;
        }
        else{
            chars[idx++]=ch;
            string str=to_string(count);//to convert count into string and also we should add each digit of a number(eg:12-'1','2')
            for(char dig:str){
                chars[idx++]=dig;
            }
        }
     }
     chars.resize(idx);//resizing to index size
     return idx;   
    }
};
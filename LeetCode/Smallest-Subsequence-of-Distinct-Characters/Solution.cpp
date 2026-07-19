1class Solution {
2public:
3    string smallestSubsequence(string s) {
4        vector<int> last(26);       
5        vector<bool> inStack(26, false); 
6        for (int i = 0; i < s.size(); i++) {
7            last[s[i] - 'a'] = i;
8        }
9
10        stack<char> st;
11
12        for (int i = 0; i < s.size(); i++) {
13            char ch = s[i];
14            if (inStack[ch - 'a'])
15                continue;
16            while (!st.empty() &&
17                   st.top() > ch &&
18                   last[st.top() - 'a'] > i) {
19
20                inStack[st.top() - 'a'] = false;
21                st.pop();
22            }
23
24            st.push(ch);
25            inStack[ch - 'a'] = true;
26        }
27        string ans = "";
28        while (!st.empty()) {
29            ans += st.top();
30            st.pop();
31        }
32
33        reverse(ans.begin(), ans.end());
34
35        return ans;
36    }
37};
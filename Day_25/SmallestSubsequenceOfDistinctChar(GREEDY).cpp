#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
          int n=s.size();

        stack<char>st;

        vector<int>last_index(26,0),vis(26,0);

        for(int i=0; i<n; i++)
        {
            last_index[s[i]-'a']=i;
        }
        

        for(int i=0; i<n; i++)
        {
            if(vis[s[i]-'a']) continue;
            
            while(!st.empty() && st.top()>s[i] && last_index[st.top()-'a']>i)
            {
                vis[st.top()-'a']--;
                st.pop();
                
            }
            st.push(s[i]);
            vis[s[i]-'a']++;
        }

        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string,int> mp;
        unordered_map<char,int> uni;
        string str = "";
        int ans = 0;   

        for (int j = 0; j < s.size(); j++) {
            str += s[j];
            uni[s[j]]++;

            while (str.size() > minSize) {
                char curr = str[0];
                uni[curr]--;
                if (uni[curr] == 0)
                    uni.erase(curr);
                str = str.substr(1);
            }


            if (str.size() >= minSize && str.size() <= maxSize) {
                if (uni.size() <= maxLetters) {
                    mp[str]++;
                    cout<<str<<" "<<mp[str]<<endl;
                    ans = max(ans, mp[str]);
                }
            }
        }
        return ans;
    }
};

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        int req = n / 4;

        unordered_map<char,int> cnt;
        for (char c : s) cnt[c]++;

       
        if (cnt['Q'] == req && cnt['W'] == req &&
            cnt['E'] == req && cnt['R'] == req)
            return 0;

        int ans = n;
        int i = 0;

        for (int j = 0; j < n; j++) {
            cnt[s[j]]--;

            while (i <= j &&
                   cnt['Q'] <= req && cnt['W'] <= req &&
                   cnt['E'] <= req && cnt['R'] <= req) {
                ans = min(ans, j - i + 1);
                cnt[s[i]]++;
                i++;
            }
        }

        return ans;
    }
};

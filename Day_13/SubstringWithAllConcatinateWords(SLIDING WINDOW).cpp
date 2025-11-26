#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty() || s.empty()) return ans;
        
        int wordCount = words.size();
        int wordLen = words[0].size();
        int totalLen = wordCount * wordLen;
        int n = s.size();
        
        unordered_map<string, int> freq;
        for (string &w : words) freq[w]++;
        
        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset;
            unordered_map<string, int> seen;
            int count = 0;
            
            for (int right = offset; right + wordLen <= n; right += wordLen) {
                string word = s.substr(right, wordLen);
                
                if (freq.count(word)) {
                    seen[word]++;
                    count++;

                    while (seen[word] > freq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == wordCount) {
                        ans.push_back(left);

                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                } else {
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        
        return ans;
    }
};
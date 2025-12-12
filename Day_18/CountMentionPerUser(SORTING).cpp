#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    static bool cmp(vector<string>& a, vector<string>& b) {
        int timeA = stoi(a[1]);
        int timeB = stoi(b[1]);

        if (timeA != timeB)
            return timeA < timeB;

        return a[0][2] < b[0][2];
    }

    vector<int> countMentions(int n, vector<vector<string>>& events) {
        unordered_set<int> online;
        vector<int> result(n, 0);
        unordered_map<int, int> onlineTime;

        for (int i = 0; i < n; i++) {
            online.insert(i);
        }

        sort(events.begin(), events.end(), cmp);

        for (auto &event : events) {
            string type = event[0];
            int timeStamp = stoi(event[1]);

            auto it = onlineTime.begin();
            while (it != onlineTime.end()) {
                if (it->second <= timeStamp) {
                    online.insert(it->first);
                    it = onlineTime.erase(it);
                } else {
                    ++it;
                }
            }

            if (type == "MESSAGE") {
                string action = event[2];

                if (action == "ALL") {
                    for (int i = 0; i < n; i++) {
                        result[i]++;
                    }
                }
                else if (action == "HERE") {
                    for (int on : online) {
                        result[on]++;
                    }
                }
                else {
                    for (int i = 0; i < action.length(); i++) {
                        if (action[i] == 'i' && i + 1 < action.length() && action[i + 1] == 'd') {
                            int j = i + 2;
                            int id = 0;
                            while (j < action.length() && isdigit(action[j])) {
                                id = id * 10 + (action[j] - '0');
                                j++;
                            }
                            if (id >= 0 && id < n)
                                result[id]++;
                            i = j - 1;
                        }
                    }
                }
            }
            else if (type == "OFFLINE") {
                int id = stoi(event[2]);
                onlineTime[id] = timeStamp + 60;
                online.erase(id);
            }
        }

        return result;
    }
};

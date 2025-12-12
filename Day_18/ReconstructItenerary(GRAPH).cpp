#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    unordered_map<string,list<string>>adj;
    vector<string>result;

    void dfs(string city){
        while(!adj[city].empty()){
            string nbr = adj[city].front();
            adj[city].pop_front();   
            dfs(nbr);
        }
        result.push_back(city);      
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for(auto tkt : tickets){
            adj[tkt[0]].push_back(tkt[1]);
        }

        for(auto &it : adj){
            it.second.sort();
        }
        
        dfs("JFK");

        reverse(result.begin(),result.end());
        return result;

    }
};
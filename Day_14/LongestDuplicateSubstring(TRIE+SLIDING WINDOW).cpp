#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
   struct TrieNode{
        TrieNode* children[26];

        TrieNode(){
            for(int i=0;i<26;i++){
                this->children[i]=NULL;
            }
        }
   };

     TrieNode* root;


    bool isAvailable(int ind , string s , int size){
    TrieNode* node=root;

    for(int i=ind ; i <ind+size;i++){
        int it=s[i]-'a';
        if(node->children[it]== NULL){
        node->children[it]=new TrieNode();
        }
        else if(i==ind+size-1)
        return true;

        node=node->children[it];
    }
    return false;
    }


    int solve(string s , int size){
        root=new TrieNode();
        
        for(int i=0;i+size<=s.size();i++){
            if(isAvailable(i,s,size))
            return i;
        }
        return -1;
    }


   
    
    string longestDupSubstring(string s) {
       int n=s.size();
       int low=1;
       int high=n-1;
       int start=-1;
       int maxLen=0;

       while(low<=high){
        int mid=low+(high-low)/2;

        int idx=solve(s,mid);
        
        if(idx!=-1){
            low=mid+1;
            start=idx;
            maxLen=mid;
        }
        else{
            high=mid-1;
        }
       }
       if(start==-1)
       return "";

       return s.substr(start,maxLen);
    }
};
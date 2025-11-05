#include<bits/stdc++.h>
using namespace std;


  struct TreeNode {
      int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    
    TreeNode* solve(TreeNode* root , int val){
        if(!root){
            return new TreeNode(val);
        }

        if(root->val<val){
            TreeNode* curr=new TreeNode(val);
            curr->left=root;
            return curr;
        }

        root->right=solve(root->right,val);
        return root;
    }
   
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        root=solve(root,val);

        return root;

    }
};
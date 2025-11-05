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

int maxi=0;
    
    int solve(TreeNode* root){
        if(!root->left && !root->right)
        return 1;

        int leftAns=0;
        if(root->left){
            leftAns=solve(root->left);
            if(root->left->val!=root->val)
            leftAns=0;
        }

        int rightAns=0;
        if(root->right){
            rightAns=solve(root->right);
            if(root->right->val!=root->val)
            rightAns=0;
        }

        maxi=max(maxi,(1+leftAns+rightAns));

        return 1+max(leftAns,rightAns);
    }
    
    int longestUnivaluePath(TreeNode* root) {
    
         if(!root)
         return 0;

        int as=solve(root);
        return maxi==0?maxi:maxi-1;
    }
};
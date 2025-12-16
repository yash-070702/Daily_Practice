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
    int count=0;
    int inorder(TreeNode* root){
        if(!root)
        return 0;
        
        int left=inorder(root->left);
        int right=inorder(root->right);

        count+=abs(left)+abs(right);

        return root->val+left+right-1;

    }
    int distributeCoins(TreeNode* root) {
        inorder(root);
        return count;
    }
};
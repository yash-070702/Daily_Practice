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
    int totalSum=0;
    long res=0;
    int MOD=1e9+7;

    int totalSumTree(TreeNode* root){
    if(!root)
    return 0;

    int left=totalSumTree(root->left);
    int right=totalSumTree(root->right);

    return left+right+root->val;
    }

    long solve(TreeNode* root){
        if(!root)
        return 0;

        long left=solve(root->left);
        long right=solve(root->right);

        long subtree=left+right+root->val;

        res=max(res,subtree*(totalSum-subtree));

        return subtree;
    } 
   
    int maxProduct(TreeNode* root) {
    totalSum=totalSumTree(root);
    solve(root);

    return res%MOD;
    }
};
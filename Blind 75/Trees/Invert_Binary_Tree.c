#include <stdio.h>
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
 


struct TreeNode* invertTree(struct TreeNode* root){
    if(root == NULL)
        return NULL;
    else
    {
        //Node
        struct TreeNode* temp;
        //Swap
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        //recursive
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
}
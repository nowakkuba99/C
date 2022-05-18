#include <stdio.h>
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };

  #define MAX(x,y) (((x)>(y))?(x):(y))

int maxDepth(struct TreeNode* root){
    int a,b=0;
    if(root == NULL)
        return 0;
    a=maxDepth(root->left);
    b=maxDepth(root->right);
    
    return MAX(a,b)+1;
}
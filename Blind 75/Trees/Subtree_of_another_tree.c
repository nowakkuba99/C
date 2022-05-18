#include <stdio.h>
#include <stdbool.h>
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    bool l,r=true;
    if(p == NULL && q == NULL)
        return 1;
    else if(p == NULL || q == NULL)
        return 0;
    l=isSameTree(p->left, q->left);
    r=isSameTree(p->right, q->right);
    return ((p->val == q->val) && l && r);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot){
    if(root == NULL)
        return ;
    return (isSubtree(root->left, subRoot)||isSubtree(root->right, subRoot)|| isSameTree(root, subRoot));
}
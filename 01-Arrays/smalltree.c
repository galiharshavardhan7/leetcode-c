/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdbool.h>

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // Both nodes are NULL -> trees match at this branch
    if (p == NULL && q == NULL) {
        return true;
    }
    
    // One node is NULL and the other is not -> structural mismatch
    if (p == NULL || q == NULL) {
        return false;
    }
    
    // Values do not match
    if (p->val != q->val) {
        return false;
    }
    
    // Recursively check left and right subtrees
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
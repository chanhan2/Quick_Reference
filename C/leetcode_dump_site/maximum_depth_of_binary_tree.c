/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int myMax(int a, int b) {
    return (a < b) ? b : a;
}

int maxDepth(struct TreeNode* root){
    if (!root) return 0;
    int l = 1 + maxDepth(root->left);
    int r = 1 + maxDepth(root->right);
    return myMax(l, r);
}

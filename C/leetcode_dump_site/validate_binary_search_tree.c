/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *newNode(int val) {
    struct TreeNode *node = NULL;
    if (!(node = (struct TreeNode *)malloc(sizeof(struct TreeNode)))) return NULL;
    
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode *add(struct TreeNode *t, int val) {
    if (!t) return newNode(val);

    if (val == t->val) return t;
    if (val < t->val) t->left = add(t->left, val);
    if (val > t->val) t->right = add(t->right, val);
    
    return t;
}

// Only copies the tree nodes, not the tree structure (ignores balancing/adjustments
// and uses basic BST insert method)
struct TreeNode *copyNodes(struct TreeNode *accum, struct TreeNode *t) {
    if (!t) return accum;

    accum = add(accum, t->val);
    accum = copyNodes(accum, t->left);
    accum = copyNodes(accum, t->right);
    return accum;
}

void deleteTree(struct TreeNode *t) {
    if (!t) return;
    
    deleteTree(t->left);
    deleteTree(t->right);
    free(t);
}

bool isValidBSTHelper(struct TreeNode *bst, struct TreeNode *t) {
    if (!bst && !t) return true;
    if (!bst && t || bst && !t) return false;
    if (bst->val != t->val) return false;
    return isValidBSTHelper(bst->left, t->left) && isValidBSTHelper(bst->right, t->right);
}

bool isValidBST(struct TreeNode* root){
    if (!root) return true;
    struct Treenode *tmp = NULL;
    tmp = copyNodes(tmp, root);
    bool result = isValidBSTHelper(tmp, root);
    deleteTree(tmp);
    return result;
}

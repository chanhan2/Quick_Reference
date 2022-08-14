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

// Copies tree along with the original structure
struct TreeNode *copy(struct TreeNode *clone, struct TreeNode *t) {
    if (!t) return clone;
    
    if (!(clone = newNode(t->val))) return NULL;

    clone->left = copy(clone->left, t->left);
    clone->right = copy(clone->right, t->right);
    return clone;
}

void deleteTree(struct TreeNode *t) {
    if (!t) return;
    
    deleteTree(t->left);
    deleteTree(t->right);
    free(t);
}

bool isSymmetricHelper(struct TreeNode *lr, struct TreeNode *rl) {
    if (!lr && !rl) return true;
    if (!lr && rl || lr && !rl) return false;
    if (lr->val != rl->val) return false;

    bool cond1 = isSymmetricHelper(lr->left, rl->right);
    bool cond2 = isSymmetricHelper(lr->right, rl->left);
    
    return cond1 && cond2;
}

bool isSymmetric(struct TreeNode* root){
    if (!root) return true;
    
    struct TreeNode *tmp = NULL;
    tmp = copy(tmp, root);
    bool result = isSymmetricHelper(root->right, root->left);
    deleteTree(tmp);
    return result;
}

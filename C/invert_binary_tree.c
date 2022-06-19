#include <stdio.h>
#include <stdlib.h>

/* Source to given definition of inverted binary tree and problem:
 * https://leetcode.com/problems/invert-binary-tree/
 */

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Basic tree functions to test functionality
struct TreeNode* new_node(int val) {
    struct TreeNode *node;
    if (!(node = (struct TreeNode*)malloc(sizeof(struct TreeNode)))) {
        printf("Failed to create new node.\n");
        return NULL;
    }

    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* principal_insert(struct TreeNode* root, struct TreeNode* node) {
    if (!root) return node;

    if (root->val == node->val) {
        printf("Key: %d already exists\nFailed to insert.\n", node->val);
        return root;
    }

    if (node->val < root->val) root->left = principal_insert(root->left, node);
    if (node->val > root->val) root->right = principal_insert(root->right, node);

    return root;
}

struct TreeNode* delete_tree(struct TreeNode* root) {
    if (!root) return NULL;

    root->left = delete_tree(root->left);
    root->right = delete_tree(root->right);
    free(root);
    return root = NULL;
}

// The actual tree inversion part
struct TreeNode* invert_tree(struct TreeNode* root) {
    if (!root) return root;

    struct TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    root->left = invert_tree(root->left);
    root->right = invert_tree(root->right);
    return root;
}

/* Functions used for VERY simple and visual output comparison testing
 * (I'm currently too lazy to think at the time of doing this LOL)
 */
int myMax(int n1, int n2) {
    if (n1 == n2) return n1;
    return (n1 < n2) ? n2 : n1;
}

int get_max_depth(struct TreeNode* root) {
    if (!root) return 0;

    return myMax(1 + get_max_depth(root->left), 1 + get_max_depth(root->right));
}

void print_nodes_at_depth(struct TreeNode* root, int depth) {
    if (!root) return;

    if (depth == 0) printf("%d,", root->val);
    else {
        print_nodes_at_depth(root->left, depth - 1);
        print_nodes_at_depth(root->right, depth - 1);
    }
}

void print_tree(struct TreeNode* root) {
    if (!root) return;

    int tree_height = get_max_depth(root);
    int i;
    for (i = 0; i < tree_height; i++) print_nodes_at_depth(root, i);
}

/* Brute force explict setup and test (LOL)
 * Too lazy to think right now.
 */
int setup_test_1() {
    struct TreeNode *n0;
    if (!(n0 = new_node(4))) {
        printf("Failed to create node\n");
        return 0;
    }

    // Setting up initial tree
    n0 = principal_insert(n0, new_node(2));
    n0 = principal_insert(n0, new_node(7));
    n0 = principal_insert(n0, new_node(1));
    n0 = principal_insert(n0, new_node(3));
    n0 = principal_insert(n0, new_node(6));
    n0 = principal_insert(n0, new_node(9));

    // Print the initial tree
    printf("Computed Input: root = [");
    print_tree(n0);
    printf("]\n");
    printf("Expected Input: root = [4,2,7,1,3,6,9,]\n");

    // Print the tree height
    printf("Current tree height: %d\n", get_max_depth(n0));
    printf("Expected tree height: 3\n");

    // Test tree inversion
    printf("--- test ---\n");
    n0 = invert_tree(n0);
    printf("Computed Output: [");
    print_tree(n0);
    printf("]\n");
    printf("Expected Output: [4,7,2,9,6,3,1,]\n");

    n0 = delete_tree(n0);
    printf("Done\n");
    return 1;
}

int main(int argc, char** argv) {
    if (!setup_test_1()) printf("Failed test case.");

    return 0;
}

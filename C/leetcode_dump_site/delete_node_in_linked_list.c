/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void deleteNode(struct ListNode* node) {
    if (node->next->next == NULL)  {
        node->val = node->next->val;
        node->next = NULL;
        free(node->next = NULL);
        return;
    }

    if (node->next != NULL) {
        node->val = node->next->val;
        return deleteNode(node->next);
    }
}

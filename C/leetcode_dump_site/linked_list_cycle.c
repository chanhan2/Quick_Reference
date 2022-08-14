/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool hasCycle(struct ListNode *head) {
    if (!head) return false;

    struct ListNode *i;
    for (i = head; i && i->val < 1000000; i = i->next) {
        i->val = 1000000;  // arbitrary large indicator value
    }
    return i != NULL;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int lstLen(struct ListNode *l) {
    if (!l) return 0;
    return 1 + lstLen(l->next);
}

struct ListNode* removeNth(struct ListNode* head, int n){
    if (!head) return NULL;
    if (n == 0) {
        struct ListNode *tmp = head->next;
        free(head);
        return tmp;
    }
    head->next = removeNth(head->next, n - 1);
    return head;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    return removeNth(head, lstLen(head) - n);
}

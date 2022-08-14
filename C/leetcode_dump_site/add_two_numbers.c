/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* newNode(int val) {
    struct ListNode* node;
    if (!(node = (struct ListNode *)malloc(sizeof(struct ListNode)))) return NULL;

    node->val = val;
    node->next = NULL;
    return node;
}

// Add new node as the new head to list
struct ListNode* addToLst(struct ListNode* lst, int val) {
    if (!lst) return newNode(val);

    struct ListNode* node;
    if (!(node = newNode(val))) return NULL;
    node->next = lst;
    return node;
}

// Appends two lists on the list l using "append to head method"
struct ListNode* addTwoLst(struct ListNode* l, struct ListNode* node) {
    if (!l) return node;
    node->next = l;
    return node;
}

struct ListNode* reverseLstHelper(struct ListNode* l, struct ListNode* accum) {
    if (!l) return accum;

    struct ListNode *tmp = l->next;
    l->next = NULL;

    accum = addTwoLst(accum, l);
    return reverseLstHelper(tmp, accum);
}

struct ListNode* reverseLst(struct ListNode* l) {
    if (!l) return NULL;

    return reverseLstHelper(l, NULL);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* l3 = NULL;
    int carry = 0;
    int place_val = 0;
    while(l1 || l2) {
        int val1 = (!l1) ? 0 : l1->val;
        int val2 = (!l2) ? 0 : l2->val;
        place_val = (val1 + val2 + carry) % 10;
        carry = (val1 + val2 + carry) / 10;
        l3 = addToLst(l3, place_val);
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    if (carry != 0) l3 = addToLst(l3, carry);
    return l3 = reverseLst(l3);
}

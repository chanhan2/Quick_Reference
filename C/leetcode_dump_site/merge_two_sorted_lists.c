/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeHelper(struct ListNode *accum, struct ListNode* list1, struct ListNode* list2){
    if (!list1 && !list2) return accum;
    if (!list1) return list2;
    if (!list2) return list1;

    if (list1->val < list2->val) {
        struct ListNode *tmp = list1->next;
        list1->next = NULL;
        if (!accum) accum = list1;
		accum->next = mergeHelper(accum->next, tmp, list2);
        return accum;
    }
    struct ListNode *tmp = list2->next;
    list2->next = NULL;
    if (!accum) accum = list2;
	accum->next = mergeHelper(accum->next, list1, tmp);
    return accum;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
	struct ListNode *result = NULL;
    return result = mergeHelper(result, list1, list2);
}

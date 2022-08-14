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

struct ListNode *addToHead(struct ListNode *l, struct ListNode *node) {
	if (!l) return node;

	node->next = l;
	return node;
}

struct ListNode *tailAppend(struct ListNode *l, struct ListNode *node) {
	if (!l) return node;

	l->next = tailAppend(l->next, node);
	return l;
}

struct ListNode *addTwoListHM(struct ListNode *accum, struct ListNode *l) {
	if (!l) return accum;

	struct ListNode *tmp = l->next;
	l->next = NULL;
	accum = addToHead(accum, l);
	return addTwoListHM(accum, tmp);
}

struct ListNode *reverse(struct ListNode *l) {
	return addTwoListHM(NULL, l);
}

// Splits the list into 2 parts at position idx and returns
// the pointer of the second portion of the list
struct ListNode *splitRestOfListAt(struct ListNode *l, int idx) {
	if (idx == 0) {
		struct ListNode *rest = l->next;
		l->next = NULL;
		return rest;
	}
	return splitRestOfListAt(l->next, idx - 1);
}

int isSameLst(struct ListNode *l1, struct ListNode *l2) {
	if (!l1 && !l2) return 1;

	if (!l1 && l2 || l1 && !l2) return 0;
	if (l1->val != l2->val) return 0;

	return isSameLst(l1->next, l2->next);
}

bool isPalindrome(struct ListNode* head){
	int len = lstLen(head);
	if (len == 1 || len == 0) return true;

	struct ListNode *snd = splitRestOfListAt(head, (len / 2) - 1);
	struct ListNode *mid_node = NULL;
	if (len % 2 != 0) {
		mid_node = snd;
		snd = snd->next;
		mid_node->next = NULL;
	}

	head = reverse(head);
	int result = isSameLst(head, snd);

	if (len % 2 != 0) snd = addToHead(snd, mid_node);
	head = reverse(head);
	head = tailAppend(head, snd);
	return result;
}

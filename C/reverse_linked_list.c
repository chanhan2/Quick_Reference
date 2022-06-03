#include <stdio.h>
#include <stdlib.h>

/* Source to given problem:  https://leetcode.com/problems/reverse-linked-list/
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

// Basic functions to create a linked list
struct ListNode* new_node(int val) {
    struct ListNode* node;
    if (!(node = (struct ListNode*)malloc(sizeof(struct ListNode)))) {
        printf("Failed to create new node.\n");
        return NULL;
    }

    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode* append_to_front(struct ListNode* head, struct ListNode* node) {
    if (!head) return node;

    node->next = head;
    return node;
}

struct ListNode* append_node(struct ListNode* head, struct ListNode* node) {
    if (!head) return node;

    head->next = append_node(head->next, node);
    return head;
}

// The actual reverse linked list part
struct ListNode* append_list_mfnt(struct ListNode* lst1, struct ListNode* lst2) {
    /* append_list_mfnt() - Appends list lst1 to list lst2 by using "append to
     *                      front" method
     */
    if (!lst1) return lst2;

    struct ListNode* rest = lst1->next;
    lst1->next = NULL;
    lst2 = append_list_mfnt(rest, lst2 = append_to_front(lst2, lst1));
    return lst2;
}

struct ListNode* reverseList(struct ListNode* head) {
    if (!head) return head;
    head = append_list_mfnt(head, NULL);
    return head;
}

/* Functions used for VERY simple and visual output comparison testing
 * (I'm currently too lazy to think at the time of doing this LOL)
 */
void print_list(struct ListNode* head) {
    if (!head) return;

    printf("%d,", head->val);
    print_list(head->next);
}

int get_list_length(struct ListNode* head) {
    if (!head) return 0;

    return 1 + get_list_length(head->next);
}

struct ListNode* delete_list(struct ListNode* head) {
    if (!head) return head;

    head->next = delete_list(head->next);
    free(head);
    return head = NULL;
}

/* Brute force explict setup and test (LOL)
 * Too lazy to think right now.
 */
int setup_test_1() {
    struct ListNode* n0;
    if (!(n0 = new_node(1))) {
        printf("Failed to create node\n");
        return 0;
    }

    // Setting up initial list
    int i;
    for (i = 2; i <= 5; i++) n0 = append_node(n0, new_node(i));

    if (get_list_length(n0) != 5) {
        printf("Failed to create list\n");
        return 0;
    }

    // Print initial linked list
    printf("Computed Input: head = [");
    print_list(n0);
    printf("]\n");
    printf("Expected Input: head = [1,2,3,4,5,]\n");

    // Reverse linked list
    n0 = reverseList(n0);

    // Test reversed linked list
    printf("Computed Output: [");
    print_list(n0);
    printf("]\n");
    printf("Expected Output: [5,4,3,2,1,]\n");

    n0 = delete_list(n0);
    printf("Done\n");
    return 1;
}

int main(int argc, char** argv) {
    if (!setup_test_1()) printf("Failed to reverse list.\n");

    return 0;
}

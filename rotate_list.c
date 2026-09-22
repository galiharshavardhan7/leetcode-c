/**
 * Problem: LeetCode 61 - Rotate List
 * Language: C
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stddef.h>

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next || k == 0) {
        return head;
    }

    // 1. Find the length of the list and the tail node
    int length = 1;
    struct ListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    // 2. Reduce k using modulo
    k = k % length;
    if (k == 0) {
        return head;
    }

    // 3. Connect the tail to the head to form a circular list
    tail->next = head;

    // 4. Find the new tail at position (length - k - 1)
    int stepsToNewTail = length - k - 1;
    struct ListNode* newTail = head;
    for (int i = 0; i < stepsToNewTail; i++) {
        newTail = newTail->next;
    }

    // 5. Break the ring and set the new head
    struct ListNode* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

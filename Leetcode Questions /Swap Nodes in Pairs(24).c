struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode* prev = dummy;
    struct ListNode* first;
    struct ListNode* second;

    while (prev->next != NULL && prev->next->next != NULL) {
        first = prev->next;
        second = first->next;

        first->next = second->next;
        second->next = first;
        prev->next = second;

        prev = first;
    }

    struct ListNode* newHead = dummy->next;
    free(dummy);
    return newHead;
}

struct ListNode* removeNodes(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* next = removeNodes(head->next);

    if (next->val > head->val)
        return next;

    head->next = next;
    return head;
}

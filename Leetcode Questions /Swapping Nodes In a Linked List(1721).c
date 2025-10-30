struct ListNode* swapNodes(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    int count = 0;
    struct ListNode* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    struct ListNode* first = head;
    for (int i = 1; i < k; i++) {
        first = first->next;
    }

    struct ListNode* second = head;
    for (int i = 1; i < count - k + 1; i++) {
        second = second->next;
    }

    int t = first->val;
    first->val = second->val;
    second->val = t;

    return head;
}

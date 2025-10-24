struct ListNode* merge(struct ListNode* left, struct ListNode* right) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tail = dummy;
    dummy->next = NULL;

    while (left != NULL && right != NULL) {
        if (left->val < right->val) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }

    if (left != NULL) tail->next = left;
    if (right != NULL) tail->next = right;

    struct ListNode* sorted = dummy->next;
    free(dummy);
    return sorted;
}

struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* slow = head;
    struct ListNode* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* mid = slow->next;
    slow->next = NULL;

    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(mid);


    return merge(left, right);
}

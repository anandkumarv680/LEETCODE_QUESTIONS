struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode beforeDummy = {0, NULL};
    struct ListNode afterDummy = {0, NULL};
    struct ListNode *before = &beforeDummy, *after = &afterDummy;

    while (head != NULL) {
        if (head->val < x) {
            before->next = head;
            before = before->next;
        } else {
            after->next = head;
            after = after->next;
        }
        head = head->next;
    }

    after->next = NULL;
    before->next = afterDummy.next;
    return beforeDummy.next;
}

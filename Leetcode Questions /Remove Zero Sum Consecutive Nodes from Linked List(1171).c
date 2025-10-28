struct ListNode* removeZeroSumSublists(struct ListNode* head) {
    if(head->val == 0 && head->next == NULL){
        return NULL;
    }
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;          
    dummy->next = head;

    struct ListNode* current = dummy;

    while (current != NULL) {
        int sum = 0;
        struct ListNode* cnext = current->next;

        while (cnext != NULL) {
            sum += cnext->val;

            if (sum == 0) {
                current->next = cnext->next;
                cnext = current->next;
                sum = 0;
                continue;
            }

            cnext = cnext->next;
        }

        current = current->next;
    }

    struct ListNode* newnode = dummy->next;
    free(dummy);
    return newnode;
}

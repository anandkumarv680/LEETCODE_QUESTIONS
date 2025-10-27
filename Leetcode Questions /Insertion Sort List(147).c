struct ListNode* insertionSortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode* current = head;   
    struct ListNode* cnext = current->next;  

    while (cnext != NULL) {
        if (current->val <= cnext->val) {
            current = cnext;
            cnext = cnext->next;
        } 
        else {
            struct ListNode* prev = dummy;

            while (prev->next->val < cnext->val) {
                prev = prev->next;
            }
            current->next = cnext->next;

            cnext->next = prev->next;
            prev->next = cnext;

            cnext = current->next;
        }
    }

    return dummy->next;
}

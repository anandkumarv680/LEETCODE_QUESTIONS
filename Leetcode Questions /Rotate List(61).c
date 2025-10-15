struct ListNode* rotateRight(struct ListNode* head, int k) {
    if( head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* current = head;
    int len = 0;
    while( current != NULL) {
        current = current->next;
        len++;
    }
    struct ListNode* mhead = head;
    struct ListNode* cycle = head;
    struct ListNode* Next;
    while( cycle != NULL) {
        if( cycle->next == NULL){
            cycle->next = mhead;
            break;
        }
        cycle = cycle->next;
    }

    k = k % len;

    for(int i = 0 ; i < len - k - 1; i++) {
        mhead = mhead->next;
    }
    Next = mhead->next;
    mhead->next = NULL;

return Next;
}

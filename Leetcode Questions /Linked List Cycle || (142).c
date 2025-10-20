struct ListNode *detectCycle(struct ListNode *head) {
    if( head == NULL || head->next == NULL){
        return NULL;
    }
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while(fast->next != NULL && fast->next->next != NULL ) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) { 
            struct ListNode* ptr1 = head;
            struct ListNode* ptr2 = slow;

            while (ptr1 != ptr2) {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }

            return ptr1; 
        }
    }
    return NULL;
}

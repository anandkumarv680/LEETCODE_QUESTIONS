void reorderList(struct ListNode* head) {
    if (!head || !head->next){
        return;
    }
    
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* prev = NULL;
    struct ListNode* curr = slow->next;
    struct ListNode* next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    slow->next = NULL;


    struct ListNode* first = head;
    struct ListNode* second = prev;
    struct ListNode* temp1;
    struct ListNode* temp2;
    while (second) {
        temp1 = first->next;
        temp2 = second->next;
        first->next = second;
        second->next = temp1;
        first = temp1;
        second = temp2;
    }
}

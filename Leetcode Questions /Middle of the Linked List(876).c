struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* check = head;
    int count = 0;

    while( check != NULL){
        count++;
        check = check->next;
    }

    while( fast->next != NULL && fast->next->next != NULL) {
        slow = slow -> next;
        fast = fast->next->next;
    }

    if( count % 2 ==0){
        return slow->next;
    }

    return slow;
}

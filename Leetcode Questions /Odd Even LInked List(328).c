struct ListNode* oddEvenList(struct ListNode* head) {

    if(head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* current = head;
    struct ListNode* cnext = current->next;
    struct ListNode* after = current->next;

    while (current != NULL && current->next != NULL && cnext != NULL && cnext->next != NULL) {
        current->next = cnext->next;
        current = current->next;
        cnext->next = current->next;
        cnext = cnext->next;

    }
    current->next = after;
    return head;
}

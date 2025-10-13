struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head == NULL) return NULL;
    if (head->next == NULL && n == 1) return NULL;

    struct ListNode* check = head;
    struct ListNode* cut = head;

    int count = 0;
    while (check != NULL) {
        count++;
        check = check->next;
    }

    if (count == n) {
        head = head->next;
        return head;
    }

    int rem = count - n;  
    int i = 1;

    while (cut != NULL && cut->next != NULL) {
        if (i == rem) {
            cut->next = cut->next->next;
            break;
        }
        cut = cut->next;
        i++;
    }

    return head;
}

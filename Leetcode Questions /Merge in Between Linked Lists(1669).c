struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){

    struct ListNode* current = list1;
    struct ListNode* left;
    struct ListNode* right;

    int l = 1;
    while ( current != NULL) {
        if(l == a){
            left = current;
            for (int i = 0 ; i < b - a + 1; i++) {
                current = current->next;
            }
            right = current->next;
            break;
        }
        current = current->next;
        l++;
    }

    left->next = list2;

    struct ListNode* ccurrent = list2;
    struct ListNode* rright;

    while( ccurrent!= NULL) {
        rright = ccurrent;
        ccurrent = ccurrent->next;
    }
    rright->next = right;

    return list1;
}

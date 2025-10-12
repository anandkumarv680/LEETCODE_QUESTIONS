
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode * l1 = headA;
    struct ListNode * l2 = headB;
    if( l1 == NULL || l2 == NULL){ 
        return NULL;
    }

    

    while( l1 != l2) {
        l1 = ( l1 == NULL) ? headB : l1 -> next;
        l2 = ( l2 == NULL) ? headA : l2 -> next;
    
    }
    return l1;
}

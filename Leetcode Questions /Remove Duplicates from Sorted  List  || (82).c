#include<stdlib.h>
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof( struct ListNode));
    dummy->next = head;
    struct ListNode* prev = dummy;
    struct ListNode* current = head;

    while( current != NULL && current->next != NULL) {

        if(current->next != NULL && current->val != current->next->val) { 
            prev = current;
            current = current->next;
        }

        else{
            int del = current->val;
            while(current->val == del){
                current = current->next;
                if(current == NULL)
                break;
            }
            prev->next = current;
        }
    }
    struct ListNode* newhead = dummy->next;
    free(dummy);
    return newhead;
}

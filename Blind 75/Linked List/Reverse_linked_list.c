#include <stdio.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

void placeAtEnd(struct ListNode* head,struct ListNode* put){
    if(head == NULL)
        return NULL;
    if(head -> next)
    {
        placeAtEnd(head->next,put);
    }
    else
        head->next = put;
    return head;
}

struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL)
        return NULL;
    struct ListNode* new=head;
    struct ListNode* new1=head;
    if(head->next)
    {
        new = reverseList(head->next);
        head->next = NULL;
        placeAtEnd(new,head);
        head=new;
    }
    return head;
}
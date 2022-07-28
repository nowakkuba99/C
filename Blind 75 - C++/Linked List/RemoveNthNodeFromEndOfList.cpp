struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next ==nullptr)
            return nullptr;
        ListNode* curr=head;
        ListNode* last=head;
        while(n>0)
        {
            last = last->next;
            n--;
        }
        if(last == nullptr)
            return head->next;
        while(last->next != nullptr)
        {
            last = last->next;
            curr = curr->next;
        }
        curr->next = curr->next->next;
        return head;
        
    }
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == nullptr)
            return;
        ListNode* single_ptr = head;
        ListNode* double_ptr = head;
        ListNode* pass = head;
        while(double_ptr->next != nullptr && double_ptr->next->next != nullptr)
        {
            single_ptr = single_ptr->next;
            double_ptr = double_ptr->next->next;
        }
        single_ptr = reverseList(single_ptr);
        mergeLists(pass,single_ptr);

    }
private:
    ListNode* reverseList(ListNode* head)
    {
        if(head == nullptr || head == nullptr)
            return head;
        ListNode* prev = nullptr;  
        ListNode* curr = head;
        ListNode* next = head;
        while(curr != nullptr)
        {
            next = curr->next;  
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void mergeLists(ListNode* Node1, ListNode* Node2)
    {
        ListNode* curr = Node1;
        ListNode* rev = Node2;
        ListNode* next = nullptr;
        while(curr != nullptr)
        {
            next = curr-> next;
            curr->next = rev;
            rev = rev->next;
            curr = curr->next; 
            curr ->next = next;        
            curr = curr->next;
        }
    }
};
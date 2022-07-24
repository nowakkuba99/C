/*
    Given heads of 2 sorted linked lists, merge into 1 sorted list
    Ex. list1 = [1,2,4], list2 = [1,3,4] -> [1,1,2,3,4,4]
*/
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 == nullptr)
            return nullptr;
        if(list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        ListNode* result;
        ListNode* curr;
        if(list1->val > list2->val)
        {
            result = list2;
            list2 = list2->next;
        }
        else
        {
            result = list1;
            list1=list1->next;
        }
        curr = result;
        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val > list2->val)
            {
                curr->next= list2;
                list2 = list2->next;
            }
            else
            {
                curr->next = list1;
                list1=list1->next;
            }
            curr = curr->next;
        }
        if(list1 == nullptr)
            curr->next = list2;
        else
            curr->next = list1;
        return result;
    }
};
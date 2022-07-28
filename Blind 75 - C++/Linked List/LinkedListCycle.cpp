struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr)
            return false;
        ListNode* hop1 = head;
        ListNode* hop2 = head;
        while(hop2->next != nullptr && hop2->next->next != nullptr)
        {
            hop1=hop1->next;
            hop2=hop2->next->next;
            if(hop1 == hop2)
                return true;
        }
        return false;
    }
};
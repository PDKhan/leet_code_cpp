class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        struct ListNode* prev = nullptr;
        struct ListNode* curr = head;
        struct ListNode* next = head;

        for(int i = 1; i < n; i++)
            next = next->next;

        while(next && next->next){
            if(prev == nullptr)
                prev = curr;
            else
                prev = prev->next;

            curr = curr->next;
            next = next->next;
        }

        if(prev == nullptr)
            head = curr->next;
        else
            prev->next = curr->next;

        return head;

    }
};

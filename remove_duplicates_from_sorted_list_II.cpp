class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;

        ListNode* new_head = nullptr;
        ListNode* tail = nullptr;
        ListNode* start = head;

        while(start){
            ListNode* end = start->next;

            while(end && start->val == end->val){
                end = end->next;
            }

            if(start->next == end){
                if(new_head == nullptr)
                    new_head = start;
                else
                    tail->next = start;
                
                tail = start;
                tail->next = nullptr;
            }

            start = end;
        }

        return new_head;
    }
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0)
            return head;

        int len = 1;
        ListNode* tail = head;

        while(tail->next){
            len++;
            tail = tail->next;
        }

        k = k % len;

        if(k == 0)
            return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;

        for(int i = 0; i < len - k; i++){
            prev = curr;
            curr = curr->next;
        }

        prev->next = nullptr;
        tail->next = head;
        return curr;
    }
};

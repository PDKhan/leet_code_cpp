class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* ls = nullptr;
        ListNode* l_tail;
        ListNode* gt = nullptr;
        ListNode* g_tail;
        ListNode* search = head;

        while(search){
            ListNode* next = search->next;
            search->next = nullptr;

            if(search->val < x){
                if(!ls)
                    ls = search;
                else
                    l_tail->next = search;
                
                l_tail = search;
            }else{
                if(!gt)
                    gt = search;
                else
                    g_tail->next = search;
                
                g_tail = search;
            }

            search = next;
        }

        if(!ls)
            return gt;
        else{
            l_tail->next = gt;

            return ls;
        }

    }
};
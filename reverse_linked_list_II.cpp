/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int idx = 1;
        ListNode* new_head = nullptr;
        ListNode* tail;
        ListNode* r_head = nullptr;
        ListNode* r_tail;
        ListNode* search = head;

        while(search){
            ListNode* next = search->next;
            search->next = nullptr;

            if(idx >= left && idx <= right){
                search->next = r_head;
                r_head = search;

                if(idx == left)
                    r_tail = r_head;
                
                if(idx == right){
                    if(new_head == nullptr)
                        new_head = r_head;
                    else
                        tail->next = r_head;
                    
                    tail = r_tail;
                }
            }else{
                if(new_head == nullptr)
                    new_head = search;
                else
                    tail->next = search;
                
                tail = search;
            }

            search = next;
            idx++;
        }

        return new_head;
    }
};

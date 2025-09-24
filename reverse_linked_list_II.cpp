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
        ListNode dummy;
        ListNode* tail = &dummy;
        ListNode* r_head = nullptr;
        ListNode* r_tail;
        ListNode* search = head;
        int cnt = 1;

        while(search){
            ListNode* next = search->next;
            if(cnt >= left && cnt <= right){
                if(!r_head)
                    r_tail = search;
                
                search->next = r_head;
                r_head = search;

                if(cnt == right){
                    tail->next = r_head;
                    tail = r_tail;
                }
            }else{
                tail->next = search;
                tail = tail->next;
            }

            cnt++;
            search = next;
        }

        return dummy.next;
    }
};
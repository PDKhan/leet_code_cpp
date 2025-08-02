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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* tail;

        while(list1 || list2){
            ListNode* cand;

            if(list1 && list2){
                if(list1->val < list2->val){
                    cand = list1;
                    list1 = list1->next;
                }else{
                    cand = list2;
                    list2 = list2->next;
                }
            }else if(list1){
                cand = list1;
                list1 = list1->next;
            }else{
                cand = list2;
                list2 = list2->next;
            }

            if(head == nullptr){
                head = cand;
                tail = head;
            }else{
                tail->next = cand;
                tail = tail->next;
            }
        }

        return head;
    }
};
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pres = head; int c = 0;
        while(pres!=NULL){
            pres = pres->next; c++;
        }
        c = c-n;
        if(c == 0){
            head = head->next; return head;
        }
        pres = head; ListNode* pre = NULL;
        while(pres!=NULL){
            if(c == 0){
                pre->next = pres->next; break;
            }
            pre = pres;
            pres = pres->next;
            c--;
        }
        return head;
    }
};
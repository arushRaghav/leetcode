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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prev = NULL;
        ListNode* curr = list1;
        b=b-a;
        while(a!=0){
            prev = curr;
            curr = curr->next;
            a--;
        }
        prev->next = list2;
        prev = curr;
        curr = list2;
        while(curr->next!=NULL){
            curr = curr->next;
        }
        while(b!=0){
            if(prev!=NULL)
                prev = prev->next;
            b--;
        }
        if(prev!=NULL){
            curr->next = prev->next;
        }
        return list1;
    }
};
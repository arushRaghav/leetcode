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
    void reorderList(ListNode* head) {
        vector<ListNode*> list;
        ListNode* curr = head;
        while(curr!=NULL){
            list.push_back(curr);
            curr = curr->next;
        }
        int n = list.size();
        for(int i=0;i<list.size()/2;i++){
            list[n-i-1]->next = list[i]->next;
            list[i]->next = list[n-i-1];
        }
        list[n/2]->next = NULL;
    }
};
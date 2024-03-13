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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int min = -1;
        ListNode* ans = NULL; ListNode* head = NULL;
        bool ch = true;
        while(ch){
            ch = false; min = -1;
            for(int i=0;i<lists.size();i++){
                if(lists[i]!=NULL){
                    ch = true;
                    if(min == -1){
                        min = i;
                    }
                    else{
                        if(lists[min]->val > lists[i]->val){
                            min = i;
                        }
                    }
                }
            }
            if(ch){
                if(ans == NULL){
                    ans = lists[min];
                    head = ans;
                    lists[min] = lists[min]->next;
                }
                else{
                    ans->next = lists[min]; ans = ans->next;
                    lists[min] = lists[min]->next;
                }
            }
        }

        return head;
    }
};
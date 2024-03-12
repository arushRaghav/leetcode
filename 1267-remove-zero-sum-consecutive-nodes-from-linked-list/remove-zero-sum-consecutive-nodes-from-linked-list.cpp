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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* cur = head; int k =0;
        while(cur!=NULL){
            k++; cur=cur->next;
        }
        int len = k;
        cur = head ;ListNode* pre=NULL;


        while(k>0){
            int sum=0; int wi = k; 
            while(wi-1>0 && cur!=NULL){
                wi--;sum = sum+cur->val;cur = cur->next;
            }
            if(cur!=NULL){sum = sum+cur->val;}
            else{
                cur = head; pre = NULL; k--; continue;
            }
            //cout<<k<<"k "<<sum<<"s ";
            // if(cur!=NULL)
            //     cout<<cur->val<<"c0 ";


            while(cur!=NULL){
                //cout<<k<<"k "<<sum<<"s ";
                if(sum==0){
                    if(pre==NULL){
                        head = cur->next; cur = cur->next;
                    }
                    else{
                        pre->next = cur->next;
                        cur = cur->next;
                    }
                    // if(cur!=NULL)
                    //     cout<<cur->val<<"c ";
                    //cout<<k<<"k1 ";
                    len = len-k;
                    if(cur==NULL){
                        cur = head; pre = NULL; k = min(k-1,len);
                    }
                    //cout<<k<<"k2 ";
                    break;
                }
                if(pre==NULL){
                    pre=head;
                    cur=cur->next;
                    if(cur!=NULL)
                        sum = sum + cur->val - head->val; 
                    continue;
                }
                pre = pre->next; cur = cur->next;
                if(cur!=NULL)
                    sum = sum + cur->val - pre->val;
            }
            // if(sum == 0){
            // k--;
            // cur = head ;pre=NULL;}
        }
        return head;
    }
};
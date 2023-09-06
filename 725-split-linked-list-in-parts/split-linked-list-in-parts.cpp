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
    
    int c = 0;
    vector<ListNode*> ans;
    void trave(ListNode* head)
    {
        if(head == NULL)
            return;
        c++;
        trave(head->next);
    }
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        trave(head);
        int n = c/k; //store least no. of items
        if(n == 0)
        {
            int cc = c;
            while(c>0)
            {
                ListNode* temp = head->next;
                head->next = NULL;
                ans.push_back(head);
                head = temp;
                c--;
            }
            for(int i = k - cc;i>0;i--)
            {
                ans.push_back(NULL);
            }
        }
        else
        {
            int o = c - n*k;
            ListNode* curr = head;
            for(int i = 0; i<k;i++)
            {
                if(o>0)
                {
                    ans.push_back(curr);
                    for(int i = 0;i<n;i++)
                    {
                        if(curr->next == NULL)
                            return ans;
                        curr = curr->next;
                    }
                    ListNode* temp = curr->next;
                    curr->next = NULL;
                    curr = temp;
                    o--;
                }

                else
                {
                    ans.push_back(curr);
                    for(int i = 0;i<n-1;i++)
                    {
                        if(curr->next == NULL)
                            return ans;
                        curr = curr->next;
                    }
                    ListNode* temp = curr->next;
                    curr->next = NULL;
                    curr = temp;
                    o--;
                }
            }
        }
        // ans.push_back(head);
        // ans.push_back(NULL);
        return ans;
    }
};
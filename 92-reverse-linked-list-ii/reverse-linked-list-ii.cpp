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
        ListNode* leftNode = NULL;
        ListNode* rightNode = NULL;
        ListNode* previousNode = NULL;
        int count = 1;
        ListNode* currentNode = head;
        while( currentNode != NULL )
        {
            if(count == left-1)
            {
                previousNode = currentNode;
            }
            if(count == left)
            {
                leftNode = currentNode;
            }
            if(count == right)
            {
                rightNode = currentNode;
            }
            count++;
            currentNode = currentNode->next;
        }
        if(left!=right)
        {
            if(previousNode != NULL)
                {
                    previousNode->next = rightNode;
                }
            else
                {
                    head = rightNode;
                }
            currentNode = leftNode->next;
            previousNode = leftNode;
            while(currentNode != rightNode && currentNode->next != NULL)
            {
                ListNode* tempNode = currentNode->next;
                currentNode->next = previousNode;
                previousNode = currentNode;
                currentNode = tempNode;
            }
            leftNode->next = rightNode->next;
            rightNode->next = previousNode;
        } 
        return head;
    }
};
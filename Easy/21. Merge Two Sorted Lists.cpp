/*

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* cur = NULL;

        if(l1 == NULL)
        {
            head = l2;
            return head;
        }
        else if(l2 == NULL)
        {
            head = l1;
            return head;
        }

        if(l1->val <= l2->val)
        {
            head = l1;
            cur = head;
            l1 = l1->next;
        }
        else
        {
            head = l2;
            cur = head;
            l2 = l2->next;
        }

        while(l1 != NULL && l2 !=NULL)
        {
            if(l1->val <= l2->val)
            {
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
        }

        if(l1 == NULL)
            cur->next = l2;
        else
            cur->next = l1;

        return head;
    }
};

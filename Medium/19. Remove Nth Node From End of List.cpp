/*

Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int len = getLen(head);
        ListNode* prev = NULL;
        ListNode* start = head;
        n = (len-n);
        if(n<0)
            n = 0;
        int indx = 0;

        while(head != NULL)
        {
            if(indx==n){
                if(prev!=NULL)
                    prev->next = head->next;
                // For deleting the starting node of the list Case:
                else
                {
                    if(start->next != NULL)
                        start = start->next;
                    else
                        start = NULL;
                }
                return start;
            }
            prev = head;
            head = head->next;
            indx++;
        }

        return start;

    }

    int getLen(ListNode* head)
    {
        int cnt = 0;
        while(head != NULL)
        {
            head = head->next;
            cnt++;
        }
        return cnt;
    }
};

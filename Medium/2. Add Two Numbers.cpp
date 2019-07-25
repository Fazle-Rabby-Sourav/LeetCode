/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
/*

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        queue< int > s1, s2;
        vector<int> res;
        ListNode* head = l1;
        int carry = 0, sum;

        while(!isNull(l1)){
            s1.push(l1->val);
            l1 = l1->next;
        }

        while(!isNull(l2)){
            s2.push(l2->val);
            l2 = l2->next;
        }

        int len1 = s1.size();
        int len2 = (int) s2.size();

        if(len1<len2)
        {
            swap(s1, s2);
            swap(l1, l2);
        }

        while(!s1.empty())
        {
            int x=0, y=0;

            if(!s1.empty())
            {
                x = s1.front();
                s1.pop();
            }
            if(!s2.empty())
            {
                y = s2.front();
                s2.pop();
            }

            sum = x+y+carry;
            if(sum>9)
            {
                sum = sum%10;
                carry = 1;
            }
            else
                carry = 0;

            res.push_back(sum);
        }
        if(carry)
              res.push_back(carry);

        ListNode* pre = NULL;
        l1 = head;
        for(int i=0; i<res.size(); i++)
        {
            int digit = res[i];
            if(!isNull(l1))
            {
                l1->val = res[i];
                pre = l1;
                l1 = l1->next;
            }
            else
            {
                ListNode *node = new ListNode(res[i]);
                pre->next = node;
                pre = node;
            }
            cout<<"res(i)"<<res[i]<<endl;
        }
        return head;
    }


    bool isNull(ListNode* head)
    {
        return head == NULL;
    }
};

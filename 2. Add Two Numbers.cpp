/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.


*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *t1 = l1;
        ListNode *t2 = l2;
        int offset = 0;
        int v1 = t1->val;
        int v2 = t2->val;
        ListNode *dummy = new ListNode(0);
        ListNode *res = dummy;
        while ( t1 || t2 || offset )
        {
            if ( t1 )
            {
                v1 = t1->val;
                t1 = t1->next;
            }
            else
                v1 = 0;
            if ( t2 )
            {
                v2 = t2->val;
                t2 = t2->next;
            }
            else
                v2 = 0;
            if ( v1 + v2 + offset >= 10 )
            {
                res->next = new ListNode( ( v1 + v2 + offset ) % 10 );
                offset = 1;
            }
            else
            {
                res->next = new ListNode( ( v1 + v2 + offset ) );
                offset = 0;
            }
            res = res->next;
        }
        res = dummy->next;
        delete dummy;
        return res;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *t1 = l1;
        ListNode *t2 = l2;
        int offset = 0;
        int v1 = t1->val;
        int v2 = t2->val;
        ListNode *dummy = new ListNode(0);
        ListNode *res = dummy;
        while ( t1 || t2 || offset )
        {
            v1 = t1? t1->val : 0;
            v2 = t2? t2->val : 0;
            t1 = t1? t1->next : t1;
            t2 = t2? t2->next : t2;
            if ( v1 + v2 + offset >= 10 )
            {
                res->next = new ListNode( ( v1 + v2 + offset ) % 10 );
                offset = 1;
                res = res->next;
            }
            else
            {
                res->next = new ListNode( ( v1 + v2 + offset ) );
                offset = 0;
                res = res->next;
            }
        }
        res = dummy->next;
        delete dummy;
        return res;
    }
};

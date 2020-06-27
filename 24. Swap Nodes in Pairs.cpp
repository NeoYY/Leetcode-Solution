/*

Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.



Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.



New_Head is used to record the head pointer,
temp to store the next starting point,
prev to store the last point in the pair

Solution two using recursive
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
    ListNode* swapPairs(ListNode* head) {
        if ( !head || !head->next ) return head;
        ListNode *Head_New = head->next, *temp = head->next->next;
        head->next->next = head;
        head->next = temp;
        ListNode *prev = head;
        head = head->next;
        while ( head && head->next )
        {
            prev->next = head->next;
            temp = head->next->next;
            head->next->next = head;
            head->next = temp;
            prev = head;
            head = head->next;
        }
        return Head_New;
    }
};



class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if ( !head || !head->next ) return head;
        ListNode *t = head->next;
        head->next = swapPairs( head->next->next );
        t->next = head;
        return t;
    }
};

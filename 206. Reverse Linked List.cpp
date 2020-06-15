/*
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

Solution one is iterative, two is recursive


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
    ListNode* reverseList(ListNode* head) {
        if ( !head || !head->next ) return head;
        ListNode *curr = head;
        ListNode *prev = nullptr;
        ListNode *nextp = head->next;
        while ( curr )
        {
            nextp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextp;
        }
        return prev;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if ( !head || !head->next ) return head;
        return Reverse( head, nullptr );
    }
    ListNode* Reverse( ListNode *head, ListNode *add )
    {
        if ( !head ) return add;
        ListNode* temp = head->next;
        head->next = add;
        return Reverse( temp, head );
    }
};

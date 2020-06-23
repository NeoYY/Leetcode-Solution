/*

Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?


Solution one need to go through the list and record the length O(N);
Solution two using fast and slow pointer;

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head, *prev = nullptr;
        int i = 0, j = 0;
        while ( temp != nullptr )
        {
            temp = temp->next;
            ++i;
        }
        temp = head;
        if ( i == n ) return temp->next;
        while ( j++ < i - n )
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        return head;
    }
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head, *prev = head;
        for ( int i = 0; i < n; ++i )
        {
            temp = temp->next;
        }
        if ( !temp ) return head->next;
        while ( temp->next )
        {
            prev = prev->next;
            temp = temp->next;
        }
        prev->next = prev->next->next;
        return head;
    }
};

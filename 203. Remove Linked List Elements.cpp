/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
        if ( !head ) return nullptr;
        ListNode *curr = head;
        ListNode *fast = head->next;
        while ( curr && curr->val == val )
        {
            curr = curr->next;
            if ( curr ) fast = curr->next;
            head = curr;
        }
        while ( curr && fast )
        {
            while ( fast && fast->val == val )
            {
                fast = fast->next;
                curr->next = fast;
            }
            curr = curr->next;
            if ( curr ) fast = curr->next;
        }
        return head;
    }
};



//Clearer version, using one less pointer
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
    ListNode* removeElements(ListNode* head, int val) {
        if ( !head ) return nullptr;
        ListNode *curr = head;
        ListNode *fast = head->next;
        while ( curr && curr->val == val )
        {
            curr = curr->next;
        }
        head = curr;
        while ( curr && curr->next )
        {
            if ( curr->next->val == val ) curr->next = curr->next->next;
            else curr = curr->next;
        }
        return head;
    }
};

/*

Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?

Solution one is fast and slow pointer
Solution two convert linked-list to vector and do comparison.
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
    bool isPalindrome(ListNode* head) {
        //if ( head == nullptr || head->next == nullptr ) return false;
        ListNode *slow = head, *fast = head, *prev = nullptr;
        while ( fast && fast->next )
        {
            fast = fast->next->next;
            ListNode *tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }
        if ( fast ) slow = slow->next;
        while ( prev && slow )
        {
            if ( prev->val != slow->val ) return false;
            else
            {
                prev = prev->next;
                slow = slow->next;
            }
        }
        return true;
    }
};


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> temp;
        while ( head )
        {
            temp.push_back( head->val );
            head = head->next;
        }
        for ( int i = 0, j = temp.size() - 1; i <= j; i++, j-- )
        {
            if ( temp[i] != temp[j] ) return false;
        }
        return true;
    }
};

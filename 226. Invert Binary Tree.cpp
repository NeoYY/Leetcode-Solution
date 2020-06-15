/*
Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.

First Solution is recursive
Second Solution is iterative, can be done queue, stack, ...
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if ( !root ) return root;
        if ( !root->left && !root->right ) return root;
        auto temp = root->left;
        root->left = invertTree( root->right );
        root->right = invertTree( temp );
        return root;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if ( !root ) return root;
        stack<TreeNode*> s;
        TreeNode* temp = root;
        s.push( temp );
        while ( !s.empty() )
        {
            temp = s.top();
            s.pop();
            swap( temp->left, temp->right );
            if ( temp->left ) s.push( temp->left );
            if ( temp->right ) s.push( temp->right );

        }
        return root;
    }
};

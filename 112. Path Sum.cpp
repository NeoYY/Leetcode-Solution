/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.


The first solution is recursive, second one is iterative.
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
    bool hasPathSum(TreeNode* root, int sum) {
        if ( !root ) return false;
        if ( !root->left && !root->right && root->val == sum ) return true;
        return hasPathSum( root->left, sum - root->val ) || 
            hasPathSum( root->right, sum - root->val );
    }
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if ( !root ) return false;
        stack<TreeNode*> s;
        s.push( root );
        while ( !s.empty() )
        {
            TreeNode *temp = s.top();
            s.pop();
            if ( !temp->left && !temp->right && ( temp->val == sum ) ) return true;
            if ( temp->left )
            {
                temp->left->val = temp->val + temp->left->val;
                s.push( temp->left );
            }
            if ( temp->right )
            {
                temp->right->val = temp->val + temp->right->val;
                s.push( temp->right );
            }
        }
        return false;

    }
};

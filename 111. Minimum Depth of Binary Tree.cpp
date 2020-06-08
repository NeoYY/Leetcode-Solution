/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.

Solution one is recursive, two is iterative.
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
    int minDepth(TreeNode* root) {
        if ( !root ) return 0;
        if ( !root->left ) return minDepth( root->right ) + 1;
        if ( !root->right ) return minDepth( root->left ) + 1;
        return min( minDepth( root->left ), minDepth( root->right ) ) + 1;
    }
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if ( !root ) return 0;
        int depth = 0;
        int width = 0;
        queue<TreeNode*> q;
        TreeNode *temp = root;
        q.push( temp );
        while ( !q.empty() )
        {
            depth++;
            width = q.size();
            for ( int i = 0; i < width; i++ )
            {
                temp = q.front();
                q.pop();                
                if ( !temp->left && !temp->right ) return depth;
                if ( temp->left ) q.push( temp->left );
                if ( temp->right ) q.push( temp->right );   
            }
        }
        return depth;
    }
};

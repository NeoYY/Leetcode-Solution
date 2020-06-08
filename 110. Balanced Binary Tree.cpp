/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.
*


Solution 1 O(n2), Solution O(n)

/

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
    bool isBalanced(TreeNode* root) {
        if ( !root ) return true;
        if ( !isBalanced( root->left ) ) return false;
        if ( !isBalanced( root->right ) ) return false;
        int DepthLeft = Depth( root->left );
        int DepthRight = Depth( root->right );
        if ( abs( DepthLeft - DepthRight ) > 1 ) return false;
        return true;
    }
    int Depth( TreeNode *root )
    {
        if ( !root ) return 0;
        return max( Depth( root->left ), Depth( root->right ) ) + 1;
    }
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return Balanced( root, height );
    }
    bool Balanced( TreeNode *root, int &height )
    {
        if ( !root ) return true;
        int left = 0;
        int right = 0;
        if ( !Balanced( root->left, left ) ) return false;
        if ( !Balanced( root->right, right ) ) return false;
        if ( abs( left - right ) > 1 ) return false;
        height = max( left, right ) + 1;
        return true;
    }
};

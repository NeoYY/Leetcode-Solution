/*

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
   
   
First solution is recursive, second one is iterative.
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
 
 //Recursive
class Solution {
public:
    bool isSymmetric( TreeNode* root ) {
        if ( !root ) return true;
        return isMirror( root->left, root->right );
    }
    bool isMirror( TreeNode* left_n, TreeNode* right_n )
    {
        if ( !left_n && !right_n ) return true;
        else if ( !left_n || !right_n ) return false;
        if ( left_n->val != right_n->val ) return false;
        return isMirror( left_n->left, right_n->right ) && isMirror( left_n->right, right_n->left);
    }
};

//Iterative using stack
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
    bool isSymmetric( TreeNode* root ) {
        if ( !root ) return true;
        stack<TreeNode*> temp;
        TreeNode* left_n = root->left;
        TreeNode* right_n = root->right;
        temp.push( left_n );
        temp.push( right_n );
        while ( !temp.empty() )
        {
            left_n = temp.top();
            temp.pop();
            right_n = temp.top();
            temp.pop();
            if ( !left_n && !right_n ) continue;
            else if ( !left_n || !right_n ) return false;
            if ( left_n->val != right_n->val ) return false;
            temp.push( left_n->left );
            temp.push( right_n->right );
            temp.push( left_n->right );
            temp.push( right_n->left );
        }
        return true;
    }
};
//Note: In this case, stack and queue can be used in the same way.



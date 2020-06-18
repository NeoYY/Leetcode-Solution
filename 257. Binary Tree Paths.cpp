/*
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3


The first solution using recursive,
Second one using iterative
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if ( root ) DFS( root, "", res );
        return res;
    }
    void DFS( TreeNode *root, string out, vector<string>& res )
    {
        if ( !root->left && !root->right ) res.push_back( out + to_string( root->val ) );
        if ( root->left ) DFS( root->left, out + to_string( root->val ) + "->", res );
        if ( root->right ) DFS( root->right, out + to_string( root->val ) + "->", res );
    }
};


class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<string> temp;
        if ( !root ) return res;
        if ( !root->left && !root->right ) return { to_string( root->val ) };
        if ( root->left ) res = binaryTreePaths( root->left );
        if ( root->right ) temp = binaryTreePaths( root->right );
        for ( auto &a: temp )
        {
          //emplace will only do one construction, which suppose to be faster
            res.emplace( res.end(), a );
        }
        for ( auto &a: res )
        {
            a = to_string( root->val ) + "->" + a;
        }
        return res;
    }
};

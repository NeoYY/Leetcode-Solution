/*
Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with same node values.

Example 1:

        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
The following are two duplicate subtrees:

      2
     /
    4
and

    4
Therefore, you need to return above trees' root in the form of a list.

Solution using DFS
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> hash;
        helper( res, hash, root );
        return res;
    }
    string helper( vector<TreeNode*>& res, unordered_map<string, int>& hash, TreeNode *root )
    {
        if ( !root ) return "#";
        string s = to_string( root->val ) + "," + helper( res, hash, root->left ) + "," + helper( res, hash, root->right );
        if ( hash[s] == 1 ) res.push_back( root );
        ++hash[s];
        return s;
    }
};

/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

Below code using BFS
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if ( !root ) return result;
        queue<TreeNode*> q;
        TreeNode *temp = root;
        q.push( temp );
        while ( !q.empty() )
        {
            vector<int> tp;
            int size = q.size();
            for ( int i = 0; i < size; i++ )
            {
                temp = q.front();
                if ( temp->left ) q.push( temp->left );
                if ( temp->right ) q.push( temp->right );
                tp.push_back( temp->val );
                q.pop();
            }
            result.push_back( tp );
        }
        reverse( result.begin(), result.end() );
        return result;
    }
};



/**
 * The second approach is recursive.
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        levelTraversal( root, 0, result ); 
        return result;
    }
    void levelTraversal( TreeNode *temp, int level, vector<vector<int>> &ret)
    {
        int vSize;
        if ( temp )
        {
            vSize = ret.size();
            if ( vSize < level + 1 )
            {
                ret.insert( ret.begin(), vector<int>(1, temp->val ));
            }
            else
            {
                ret[vSize - 1 - level].push_back( temp->val );
            }
            levelTraversal( temp->left, level + 1, ret );
            levelTraversal( temp->right, level + 1, ret );            
        }
    }
};

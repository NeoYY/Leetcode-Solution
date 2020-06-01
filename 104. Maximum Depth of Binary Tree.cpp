/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.

This problem can be done recursively and iteratively.
*/

/**
Recursive Solution
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
    int maxDepth(TreeNode* root) {
        if ( !root ) return 0;
        int l_c = 0;
        int r_c = 0;
        l_c = maxDepth( root->left );
        r_c = maxDepth( root->right );
        if ( l_c > r_c ) 
        {
            return l_c + 1;
        }
        return r_c + 1;
    }
};


/**
 * Iterative Solution Using queue
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
    int maxDepth(TreeNode* root) {
        if ( !root ) return 0;
        int count = 0;
        queue<TreeNode*> temp;
        temp.push( root );
        while ( !temp.empty() )
        {
            count++;
            int size = temp.size();
            int t_count = 0;
            while ( t_count < size )
            {
                t_count++;
                root = temp.front();
                temp.pop();                
                if ( root->left ) temp.push( root->left );
                if ( root->right ) temp.push( root->right );
            }
        }
        return count;
    }
};


/**
 * Using DFS, stack, different approach from queue
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
    int maxDepth(TreeNode* root) {
        if ( !root ) return 0;
        int depth = 0;
        
        stack<TreeNode*> Tree_S;
        stack<int> tag;
        
        TreeNode* curr = root;
        while ( curr || !Tree_S.empty() )
        {
            while ( curr )
            {
                Tree_S.push( curr );
                tag.push(0);
                curr = curr->left;
                
            }
            if ( tag.top() == 1 )
            {
                depth = depth > Tree_S.size() ? depth : Tree_S.size();
                tag.pop();
                Tree_S.pop();
                curr = nullptr;
            }
            else
            {
                curr = Tree_S.top();
                curr = curr->right;
                tag.pop();
                tag.push(1);
            }
        }
        return depth;
    }
};


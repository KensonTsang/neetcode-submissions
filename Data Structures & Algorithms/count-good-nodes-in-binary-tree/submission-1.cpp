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

    int count;
    
    void dfs(TreeNode* root, int curMax) {
        if (root == nullptr) {
            return;
        }

        dfs(root->left, max(curMax, root->val));
        dfs(root->right, max(curMax, root->val));

        if (root->val >= curMax) {
            count++;
        }
    }



    int goodNodes(TreeNode* root) {
        count = 0;
        dfs(root, root->val);
        return count;
    }
};

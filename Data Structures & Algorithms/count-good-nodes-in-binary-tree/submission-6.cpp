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
    
    int dfs(TreeNode* root, int parentMax) {

        if (root == nullptr) {
            return 0;
        }

        int goodCount = 0;

        if (root->val >= parentMax) {
            goodCount++;
        }

        goodCount += dfs(root->left, max(parentMax, root->val));
        goodCount += dfs(root->right, max(parentMax, root->val));

        
        return goodCount;

    }

    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
};

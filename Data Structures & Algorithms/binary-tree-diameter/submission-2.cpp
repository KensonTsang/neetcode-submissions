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

    int result = 0;

    int dfs(TreeNode* root) {
        
        if (root == nullptr) {
            return 0;
        }
        
        int leftMax = dfs(root->left);
        int rightMax = dfs(root->right);
        
        result = max(result, leftMax + rightMax);

        return 1 + max(leftMax, rightMax);

    }


    int diameterOfBinaryTree(TreeNode* root) {
        
        dfs(root);
        return result;

    }
};

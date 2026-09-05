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

    int goodCount;

    void dfs (TreeNode* node, int parentMax) {

        if (node == nullptr) {
            return;
        }

        if (node->val >= parentMax) {
            goodCount++;
        }

        dfs(node->left, max(parentMax, node->val));
        dfs(node->right, max(parentMax, node->val));
    

    }


    int goodNodes(TreeNode* root) {

        goodCount = 0;

        dfs(root, INT_MIN);

        return goodCount;

    }
};

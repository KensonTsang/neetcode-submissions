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
    int maxDepth(TreeNode* root) {
        
        if (root == nullptr)
            return 0;

        queue<TreeNode*> q;
        q.push(root);

        int depth = 0;
        
        while (q.size() > 0) {
            int qSize = q.size();

            for (int i = 0 ; i < qSize ; i++) {
                auto item = q.front();
                q.pop();
                if (item->left != nullptr) q.push(item->left);
                if (item->right != nullptr) q.push(item->right);
            }

            depth++;
        }

        return depth;



    }
};

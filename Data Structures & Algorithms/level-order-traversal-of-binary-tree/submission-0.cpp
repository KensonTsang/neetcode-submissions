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
    vector<vector<int>> levelOrder(TreeNode* root) {

        if (root == nullptr) {
            return {};
        }

        vector<vector<int>> result{};

        queue<TreeNode*> q{};
        q.push(root);

        while(q.size() > 0) {
            int queueSize = q.size();
            vector<int> r(queueSize);
            for (auto i = 0 ; i < queueSize ; i++) {
                auto* node = q.front();
                q.pop();

                r[i] = node->val;

                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }

            result.push_back(r);
        }
    
        return result;

    }
};

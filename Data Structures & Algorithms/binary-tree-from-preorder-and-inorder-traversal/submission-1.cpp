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

    unordered_map<int, int> inorderIndexMap;

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd) {
    
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        TreeNode* node = new TreeNode(preorder[preStart]);
        
        int mid = inorderIndexMap[preorder[preStart]];
        int leftSize = mid - inStart;

        node->left  = build(preorder, preStart + 1, preStart + leftSize, inorder, inStart, mid - 1);
        node->right = build(preorder, preStart + leftSize + 1, preEnd, inorder, mid + 1, inEnd);

        return node;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0 ; i < inorder.size() ; ++i){
            inorderIndexMap[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};

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

class Codec {
public:

    void serialize(TreeNode* root, stringstream& out) {
        
        if (root == nullptr) {
            out << "N#";
            return;
        }

        if (root->val >= 0) {
            out << "+";
        };

        out << root->val << "#";
        serialize(root->left, out);
        serialize(root->right, out);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        serialize(root, ss);
        return ss.str();
    }

    TreeNode* deserialize(string& data, int& index) {

        if (data[index] == 'N') {
            index += 2;
            return nullptr;            
        }

        int val = 0;        
        bool isNegative = (data[index++] == '-');

        while(data[index] != '#') {                     
            val = (val * 10) + (data[index] - '0');                         
            index++;
        }
        
        if (isNegative) val *= -1;
        auto* root = new TreeNode(val);


        index++;
        root->left = deserialize(data, index);        
        root->right = deserialize(data, index);

        return root;

    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return deserialize(data, index);
    }
};

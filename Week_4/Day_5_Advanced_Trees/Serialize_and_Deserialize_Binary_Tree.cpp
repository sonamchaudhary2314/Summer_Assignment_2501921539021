/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

class Codec {
public:

    string serialize(TreeNode* root) {

        if (!root)
            return "#,";

        return to_string(root->val) + "," +
               serialize(root->left) +
               serialize(root->right);
    }

    TreeNode* deserializeHelper(stringstream& ss) {

        string val;
        getline(ss, val, ',');

        if (val == "#")
            return nullptr;

        TreeNode* node = new TreeNode(stoi(val));

        node->left = deserializeHelper(ss);
        node->right = deserializeHelper(ss);

        return node;
    }

    TreeNode* deserialize(string data) {

        stringstream ss(data);
        return deserializeHelper(ss);
    }
};

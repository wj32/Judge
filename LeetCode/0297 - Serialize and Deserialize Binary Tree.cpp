/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void serialize(string* s, TreeNode* node) {
        size_t index = s->size();
        s->append(1, ' ');
        s->append(to_string(node->val));
        int children = 0;
        if (node->left != nullptr) {
            children |= 0x1;
            serialize(s, node->left);
        }
        if (node->right != nullptr) {
            children |= 0x2;
            serialize(s, node->right);
        }
        (*s)[index] = 'a' + children;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        if (root != nullptr) {
            serialize(&s, root);
        }
        return s;
    }

    TreeNode* deserialize(const string& s, size_t* index) {
        const int children = s[*index] - 'a';
        (*index)++;
        size_t valueIndex = *index;
        while ((*index < s.size()) && ((s[*index] < 'a') || (s[*index] > 'd'))) {
            (*index)++;
        }
        const auto node = new TreeNode(stoi(s.substr(valueIndex, *index - valueIndex)));
        if ((children & 0x1) != 0) {
            node->left = deserialize(s, index);
        }
        if ((children & 0x2) != 0) {
            node->right = deserialize(s, index);
        }
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) {
            return nullptr;
        }
        size_t index = 0;
        return deserialize(data, &index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

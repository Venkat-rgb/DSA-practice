/* The Codec class provides methods to serialize and deserialize a binary tree to and from a single
string representation. */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "#,";

        return to_string(root -> val) + "," + serialize(root -> left) + serialize(root -> right);
    }

    TreeNode *deserializeHelper(queue <string> &nodes) {
        if(nodes.empty()) return NULL;

        string frontNode = nodes.front();
        nodes.pop();

        if(frontNode == "#") return NULL;

        TreeNode *root = new TreeNode(stoi(frontNode));
        root -> left = deserializeHelper(nodes);
        root -> right = deserializeHelper(nodes);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue <string> nodes;

        int start = 0, end = 0;
        while(end < data.size()) {
            if(data[end] == ',') {
                nodes.push(data.substr(start, end - start));
                end++;
                start = end;
            }
            else {
                end++;
            }
        }
        
        return deserializeHelper(nodes);
    }
};
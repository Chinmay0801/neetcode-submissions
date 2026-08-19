class Codec {
public:

    // Serialize — preorder DFS
    void dfs(TreeNode* node, string& s) {
        if (!node) {
            s += "N,";
            return;
        }
        s += to_string(node->val) + ",";
        dfs(node->left, s);
        dfs(node->right, s);
    }

    string serialize(TreeNode* root) {
        string s = "";
        dfs(root, s);
        return s;
    }

    // Deserialize — preorder DFS using index
    TreeNode* dfsDeserialize(vector<string>& tokens, int& i) {
        if (tokens[i] == "N") {
            i++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(tokens[i]));
        i++;
        node->left  = dfsDeserialize(tokens, i);
        node->right = dfsDeserialize(tokens, i);
        return node;
    }

    TreeNode* deserialize(string data) {
        vector<string> tokens;
        string token = "";

        // split by ','
        for (char c : data) {
            if (c == ',') {
                tokens.push_back(token);
                token = "";
            } else {
                token += c;
            }
        }

        int i = 0;
        return dfsDeserialize(tokens, i);
    }
};
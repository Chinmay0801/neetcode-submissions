class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root,
                                   TreeNode* p,
                                   TreeNode* q) {

        while (root != nullptr) {

            // Both nodes are smaller
            if (p->val < root->val &&
                q->val < root->val) {

                root = root->left;
            }

            // Both nodes are larger
            else if (p->val > root->val &&
                     q->val > root->val) {

                root = root->right;
            }

            // They split OR root is p/q
            else {
                return root;
            }
        }

        return nullptr;
    }
};
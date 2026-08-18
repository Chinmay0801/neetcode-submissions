class Solution {
public:
    int maxSum = INT_MIN;

    int dfs(TreeNode* root) {

        // Base case
        if (root == nullptr)
            return 0;

        // Best contribution from left subtree
        int left = max(0, dfs(root->left));

        // Best contribution from right subtree
        int right = max(0, dfs(root->right));

        // Path passing through current node
        int currentPath = left + root->val + right;

        // Update global answer
        maxSum = max(maxSum, currentPath);

        // Return best one-sided path to parent
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
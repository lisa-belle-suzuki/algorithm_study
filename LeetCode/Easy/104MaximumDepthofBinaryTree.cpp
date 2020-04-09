/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int max_depth = 0;
    int maxDepth(TreeNode* root) {
        dfs(root, 1);
        return max_depth;
    }

    void dfs(TreeNode* node, int depth){
        if (node == NULL) return;
        if (depth > max_depth) max_depth = depth;
        dfs(node->left, depth+1);
        dfs(node->right, depth+1);
    }
};
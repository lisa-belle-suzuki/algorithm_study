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
    set<int> levels;
    unordered_map<int, vector<int>> dict;
    vector<vector<int>> levelOrder(TreeNode* root) {
        search(root, 0);
        vector<vector<int>> ans;
        for(auto level: levels){
            ans.push_back(dict[level]);
        }
        return ans;
    }
    void search(TreeNode* node, int level){
        if (node == NULL) return;
        if (dict.count(level)>0){
            dict[level].push_back(node->val);
        }else{
            levels.insert(level);
            vector<int> num = {node->val};
            dict[level] = num;
        }
        search(node->left, level + 1);
        search(node->right, level + 1);
    }
};
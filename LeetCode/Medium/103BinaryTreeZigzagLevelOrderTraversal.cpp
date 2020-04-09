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
    unordered_map<int, vector<int>> mp;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        dfs(root, 0);
        vector<vector<int>> ans;
        for(auto level: levels){
            ans.push_back(mp[level]);
        }
        return ans;
    }

    void dfs(TreeNode* node, int level){
        if (node == NULL) return;
        levels.insert(level);
        if (level % 2 == 0){
            if (mp.count(level)>0){
                mp[level].push_back(node->val);
            }else{
                vector<int> num = {node->val};
                mp[level] = num;
            }
        }else{
            if (mp.count(level)>0){
                mp[level].insert(mp[level].begin(), node->val);
            }else{
                vector<int> num = {node->val};
                mp[level] = num;
            }
        }
        dfs(node->left, level+1);
        dfs(node->right, level+1);
    }
};
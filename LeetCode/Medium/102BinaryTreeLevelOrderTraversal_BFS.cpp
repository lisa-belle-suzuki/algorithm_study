class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> numsInCurLevel;
            int q_length = q.size();
            for(int i=0; i<q_length; i++){
                TreeNode* numNode = q.front();
                q.pop();
                if (numNode == NULL) continue;
                numsInCurLevel.push_back(numNode->val);
                q.push(numNode->left);
                q.push(numNode->right);
            }
            if (numsInCurLevel.empty()) break;
            ans.push_back(numsInCurLevel);
        }
        return ans;
    }
};
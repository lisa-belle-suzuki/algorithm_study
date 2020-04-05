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
    int longest = 0;

    // 自分以下の，左右にまたがらない最長のpath
    int longest_straight_path(TreeNode* node){
        // cout << "left = " << node->left->val << " right = " << node->right->val << endl;
        if (node == NULL) return 0;
        int cur_longest = 0;
        int left_longest, right_longest;
        if (node->left) left_longest = longest_straight_path(node->left);
        if (node->right) right_longest = longest_straight_path(node->right);
        if (node->left && node->left->val == node->val){//自分の左の子供の値と自分の値が等しい
          cur_longest = max(cur_longest, left_longest+1);
          if (node->right && node->right->val == node->val){//自分の右の子供の値と自分の値が等しい
             longest = max(longest, left_longest+right_longest+2);
          }
        }
        if (node->right && node->right->val == node->val){//自分の右の子供の値と自分の値が等しい
          cur_longest = max(cur_longest, right_longest+1);
        }
        // cout << node->val <<": "<<"cur_longest = " << cur_longest << endl;
        longest = max(longest, cur_longest);
        return cur_longest;
    }

    int longestUnivaluePath(TreeNode* root) {
        return max(longest, longest_straight_path(root));
    }
};



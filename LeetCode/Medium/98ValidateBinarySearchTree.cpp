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
    bool isValidBST(TreeNode* root){
        return isOK(root, LLONG_MIN, LLONG_MAX);
    }
    bool isOK(TreeNode* root, long long minNum, long long maxNum) {
        if (root == NULL){
            return true;
        }
        if (root->left != NULL && root->left->val >= root->val){
            cout << "left error" << endl;
            return false;
        }
        if (root->right != NULL && root->right->val <= root->val){
            cout << "right error" << endl;
            return false;
        }
        if (root->val <= minNum){
            cout << root->val << "のとき，" << "<= minNum" << endl;
            return false;
        }
        if (root->val >= maxNum){
            cout << root->val << "のとき，" << ">= maxNum" << endl;
            return false;
        }
        if (isOK(root->left, minNum, minll(maxNum, root->val)) && 
            isOK(root->right, maxll(minNum, root->val), maxNum)){
            return true;
        }else{
            return false;
        }
    }

    long long minll(long long a, long long b){
        if (a < b) return a;
        else return b;
    }
    long long maxll(long long a, long long b){
        if (a > b) return a;
        else return b;
    }
};
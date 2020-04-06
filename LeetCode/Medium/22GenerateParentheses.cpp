class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        paren_str("", n, n, ans);
        return ans;
    }

    void paren_str(string cur, int leftRemain, int rightRemain, vector<string>& ans){
        if (leftRemain==0 && rightRemain==0){
            ans.push_back(cur);
            return;
        }
        if (leftRemain > 0){
            paren_str(cur+'(', leftRemain-1, rightRemain, ans);
        }
        if (rightRemain > 0 && rightRemain > leftRemain){
            paren_str(cur+')', leftRemain, rightRemain - 1, ans);
        }
    }
};
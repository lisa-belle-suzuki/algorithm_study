class Solution {
public:
    vector<vector<int>> answer;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        search(cur, nums);
        return answer;
    }

    void search(vector<int> cur, vector<int> rest){
        if (rest.size()==0){
            answer.push_back(cur); return;
        }
        int a = rest.back();
        rest.pop_back();
        search(cur, rest);
        cur.push_back(a);
        search(cur, rest);
    }
};
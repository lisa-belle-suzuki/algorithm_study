class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        search(cur, nums);
        return result;
    }
    void search(vector<int> cur, vector<int> rest){
        if (rest.size()==0){
            result.push_back(cur);
            return;
        }
        for(int i=0; i<rest.size(); i++){
            cur.push_back(rest[i]);
            vector<int> new_rest = rest;
            new_rest.erase(new_rest.begin()+i);
            search(cur, new_rest);
            cur.pop_back();
        }
    }
};
class Solution {
public:
    vector<vector<int>> solutions;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        search(0, cur, target, candidates);
        return solutions;
    }

    void search(int n, vector<int> cur, int target, const vector<int>& candidates){
        int sum_of_cur = sum_of_vector(cur);
        if (sum_of_cur==target){
            solutions.push_back(cur);
            return;
        }else if (sum_of_cur > target){
            return;
        }else{// sum_of_cur < target
            if (n >= candidates.size()) return;
            search(n+1, cur, target, candidates);
            for(int i=0; i<(target/(candidates[n])); i++){
                cur.push_back(candidates[n]);
                search(n+1, cur, target, candidates);
            }
        }
    }

    int sum_of_vector(const vector<int>& nums){
        int ret = 0;
        for(int i=0; i<nums.size(); i++){
            ret += nums[i];
        }
        return ret;
    }
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> hash;
        set<string> st;
        string sorted;
        for(int i=0; i<strs.size(); i++){
            sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            if (hash.count(sorted)){
                hash[sorted].push_back(strs[i]);
            }else{
                st.insert(sorted);
                hash[sorted] = {strs[i]};
            }
        }
        for(auto x: st){
            result.push_back(hash[x]);
        }
        return result;
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==0){
            return 0;
        }else{
            int prev = nums[0]+1;
            for (auto it = nums.begin(); it != nums.end();) {
                // 条件一致した要素を削除する
                if (*it == prev) {
                    // 削除された要素の次を指すイテレータが返される。
                    it = nums.erase(it);
                }else {
                    prev = *it;
                    ++it;
                }
            }
            return nums.size();   
        }
    }
};
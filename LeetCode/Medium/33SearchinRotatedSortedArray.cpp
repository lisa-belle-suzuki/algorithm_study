class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size()==0) return -1;
        if (nums.size()==1){
            if (nums[0]==target) return 0;
            else return -1;
        }
        //(1)sorted->にぶたん
        if (nums.front() < nums.back()){
            int left = 0, right = nums.size()-1;
            while(left <= right){
                int center = (left + right) / 2;
                if (nums[center]==target) return center;
                if (nums[center] < target) left = center+1;
                else right = center-1;
            }
            return -1;
        }else{
        //(2)not sorted
            if (target < nums.front() && target > nums.back()){
                return -1;
            }
            // 普通のにぶたんと同じようにやる
            return special_binary_search(nums, target);
        }
    }

    int special_binary_search(vector<int>& nums, int target){
        // まずminIdxを探す
        int left = 0, right = nums.size()-1, center, minIdx = -1;
        while(left <= right){
            // cout << "left:" << left << " right:" << right <<" ";
            center = (left + right) / 2;
            // cout << "center;" << center << endl;
            if (nums[center] > nums[center+1]){
                minIdx = center+1;
                break;
            }else if (nums[left] <= nums[center]){
                left = center + 1;
            }else{
                right = center - 1;
            }
        }
        // cout << "minIdx:" << minIdx << endl; 
        //minIdxから始まるにぶたんをとく
        left = 0, right = nums.size()-1;
        int center_mod;
        while(left <= right){
            center = (left + right) / 2;
            center_mod = (center + minIdx)%nums.size();
            if (nums[center_mod]==target) return center_mod;
            if (nums[center_mod] < target) left = center+1;
            else right = center-1;
        }
        return -1;
    }
};
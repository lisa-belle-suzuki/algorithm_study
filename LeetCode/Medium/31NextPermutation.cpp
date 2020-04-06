class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // <になるIdxを探す
        int increaseIdx = -1;
        for(int i=nums.size()-2; i>=0; i--){
            if (nums[i] < nums[i+1]){
                increaseIdx = i;
                break;
            }
        }
        // cout << "increaseIdx = " << increaseIdx << endl;

        // 最初に戻る
        if (increaseIdx==-1){
            sort(nums.begin(), nums.end());
            return;
        }

        // 下1桁をひっくり返す
        if (increaseIdx==nums.size()-2){
            // swap
            // cout << "下1桁をひっくり返す" << endl;
            int a = nums[nums.size()-2];
            nums[nums.size()-2] = nums[nums.size()-1];
            nums[nums.size()-1] = a;
            return;
        }

        // increaseIdx以下を並べ替える
        int original = nums[increaseIdx];
        int minLarger = INT_MAX;
        int minLargerIdx = -1;
        for(int i=increaseIdx; i<nums.size(); i++){
            if (nums[i] > original && nums[i] < minLarger){
                minLarger = nums[i];
                minLargerIdx = i;
            }
        }
        // swap
        int a = nums[increaseIdx];
        nums[increaseIdx] = nums[minLargerIdx];
        nums[minLargerIdx] = a;

        // sort the remaining array
        int i=increaseIdx+1;
        while(i<nums.size()){
            // find minIdx
            int min = INT_MAX;
            int minIdx = -1;
            for(int j=i; j<nums.size(); j++){
                if (nums[j] < min){
                    min = nums[j];
                    minIdx = j;
                }
            }
            //swap
            int a = nums[i];
            nums[i] = nums[minIdx];
            nums[minIdx] = a;

            i++;
        }
        return;
    }
};
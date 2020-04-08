class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int maxNum = INT_MIN, minNum = INT_MAX;
        int sum = 0, maxIdx = -1;
        int minSum = 0;
        int maxAns = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if (nums[i] > maxNum) maxNum = nums[i];
            if (nums[i] < minNum) minNum = nums[i];
            sum += nums[i];
            if (sum > maxSum){
                maxSum = sum;
                maxIdx = i;
            }
            if (sum - minSum > maxAns) maxAns = sum - minSum;
            if (sum < minSum) minSum = sum;
        }
        return maxAns;
    }
};
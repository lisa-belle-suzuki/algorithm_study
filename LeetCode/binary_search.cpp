# include <bits/stdc++.h>

using namespace std;

// sorted_numsの中にtargetが存在していたらそのidxを，存在していなかったら-1を返す
int binary_search(vector<int>& sorted_nums, int target){
    int left = 0, right = sorted_nums.size()-1, cur;
    while(left <= right){
        cur = (left + right) / 2;
        if (sorted_nums[cur]==target) return cur;
        if (target < sorted_nums[cur]){
            right = cur - 1;
        }else if (target > sorted_nums[cur]){
            left = cur + 1;
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {0,1,2,3,4,6};
    sort(nums.begin(), nums.end());
    cout << binary_search(nums, 5) << endl;
    cout << binary_search(nums, 6) << endl;
    cout << binary_search(nums, 3) << endl;
    return 0;
}
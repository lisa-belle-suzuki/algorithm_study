class Solution {
public:
    int k_, division_sum;
    vector<int> nums_;
    int cnt[16] = {0};
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        k_ = k;
        nums_ = nums;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        if (sum % k != 0) return false;
        division_sum = sum / k;
        cout << "division_sum = " << division_sum << endl;
        int *state = new int[nums.size()];
        for(int i=0; i<nums.size(); i++){
            state[i] = -1;
        }
        if (search(state, 0)){
            delete[] state; return true;
        }else{
            delete[] state; return false;
        }
    }
    
    bool search(int* state, int n){
        // cout << "state = [";
        // for(int i=0; i<nums_.size(); i++){
        //     cout << state[i] << ", ";
        // }
        // cout << "]" << endl;
        for(int i=0; i<16; i++){
            cnt[i] = 0;
        }
        for(int i=0; i<n; i++){
            if (state[i]!= -1){
                if (state[i] >= 16) cout << state[i] << "AAAAA" << endl;
                cnt[state[i]] += nums_[i];           
            }
        }
        if (n==nums_.size()){
            for(int i=0; i<k_; i++){
                if (cnt[i]!=division_sum){
                    // cout << "xxx" << endl;
                    return false;
                }
            }
            return true;
        }else{
            for(int i=0; i<k_; i++){
                if (cnt[i] > division_sum){
                    // cout << "ppp" << endl;
                    return false;
                }
            }
        }

        // ダブりがないように
        int max_num_division = -1;
        for(int i=0; i<nums_.size(); i++){
            if (state[i] > max_num_division) {
                max_num_division = state[i];   
            }
        }
        for(int i=0; i<=min_(max_num_division+1, nums_.size()-1); i++){
            state[n] = i;
            if (search(state, n+1)){
                return true;
            }
        }
        return false;
    }
    
    int min_(int A, int B){
        if (A < B) return A;
        else return B;
    }
};

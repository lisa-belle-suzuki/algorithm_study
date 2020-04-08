class Solution {
public:
    unordered_map<int, double> dp;
    double myPow(double x, int n) {
        double ans;
        if (dp.count(n)>0) return dp[n];
        else if (n == 0) ans = 1;
        else if (n==1) ans = x;
        else if (n>0){
            if (n%2==0) ans = myPow(x, n/2) * myPow(x, n/2);
            else ans = x * myPow(x, n/2) * myPow(x, n/2);
        } else{
            if (n%2==0) ans = myPow(x, n/2) * myPow(x, n/2);
            else ans = myPow(x, n/2) * myPow(x, n/2) / x;
        }
        dp[n] = ans;
        return ans;
    }
};
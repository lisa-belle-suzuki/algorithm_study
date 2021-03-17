#include <bits/stdc++.h>

using namespace std;

int N;
int A[10002];
int dp[10002][10002];
int ret = 0;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        dp[i][i] = A[i];
        ret = max(ret, A[i]);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            dp[i][j] = min(dp[i][j - 1], A[j]);
            // cout << dp[i][j] << endl;
            ret = max(ret, dp[i][j] * (j - i + 1));
        }
    }
    cout << ret << endl;
    return 0;
}
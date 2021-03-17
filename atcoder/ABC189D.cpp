#include <bits/stdc++.h>

using namespace std;

long long int n;
string S[61];
long long int dp[61][2];

int main()
{
    cin >> n;
    for (long long int i = 1; i <= n; i++)
    {
        cin >> S[i];
    }
    dp[0][0] = 1;
    dp[0][1] = 1;
    for (long long int i = 1; i <= n; i++)
    {
        if (S[i] == "AND")
        {
            dp[i][0] = dp[i - 1][0] * 1;
            dp[i][1] = dp[i - 1][0] + dp[i - 1][1] * 2;
        }
        else
        {
            dp[i][0] = dp[i - 1][0] * 2 + dp[i - 1][1];
            dp[i][1] = dp[i - 1][1];
        }
    }

    cout << dp[n][0] << endl;

    return 0;
}
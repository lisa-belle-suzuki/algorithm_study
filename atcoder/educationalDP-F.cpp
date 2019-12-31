# include <algorithm>
# include <iostream>
# include <cmath>
# include <string>
# include <vector>
#include <numeric>

const long long int INF = 1e14;
typedef long long int ll;
#define rep(i,n) for(ll i=0; i<n; i++)
#define Rep(i,n) for(ll i=1; i<=n; i++)
// #define orep(i,s,e) for(ll i=s; i<e; i++)
// #define oRep(i,s,e) for(ll i=s; i<=e; i++)


using namespace std;

int main() {
    string s,t;
    cin >> s;
    cin >> t;
    s = " " + s;
    t = " " + t;

    string dp[s.length()+4][t.length()+4];
    rep(i, t.length()+1) dp[0][i] = "";
    rep(i, s.length()+1) dp[i][0] = "";

    if (s[1]==t[1]) dp[1][1] = s[1];
    else dp[1][1] = "";

    Rep(i, s.length()) {
        Rep(j, t.length()) {
            if (s[i]==t[j]) dp[i][j] = dp[i-1][j-1]+s[i];
            else {
                dp[i][j] = dp[i-1][j];
                if (dp[i][j-1].length() > dp[i][j].length()){
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
    }
    // rep(i, s.length()+1){
    //     rep(j, t.length()+1){
    //         cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
    //     }
    // }

    cout << dp[s.length()][t.length()] << endl;

    return 0;
}

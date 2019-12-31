# include <iostream>
# include <vector>

using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int count__[35];
int total[40];


int main() {
    int n,m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        int k;
        cin >> k;
        while(k--){
            int a;
            cin >> a;
            count__[a]++;
        }
    }
    int ans=0;
    for (int i=1; i<m+1; i++) {
        if (count__[i]==n) {
            ans ++;
        }
    }
    cout << ans << endl;
    return 0;

    // int N, M;
    // cin >> N >> M;
    // for(int i = 1; i <= N; i++) {
    //     int K;
    //     cin >> K;
    //     while(K--){
    //         int a;
    //         cin >> a;
    //         total[a]++;
    //     }
    // }
    // int ans = 0;
    // for(int i = 1; i <= M; i++) {
    //     if(total[i] == N) {
    //         ans++;
    //     }
    // }
    // cout << ans << endl;
    // return 0;
}
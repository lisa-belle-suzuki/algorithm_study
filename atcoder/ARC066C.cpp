#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <string>
#include <vector>

const long long int INF = 1e9;
typedef long long int ll;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define Rep(i, n) for(int i = 1; i <= (int)(n); i++)
#define llrep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define llRep(i, n) for(ll i = 1; i <= (ll)(n); i++)

using namespace std;

struct Point{
	int x,y;
};

bool vector_finder(std::vector<int> vec, int number) {
    auto itr = std::find(vec.begin(), vec.end(), number);
    size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return true;
    }
  else { // 発見できなかったとき
    return false;
    }
}

//2にん
// 0,1
// 1,1

//6にん
// 0,1,2,3,4,5
// 5,3,1,1,3,5

//7にん
// 0,1,2,3,4,5,6
// 6,4,2,0,2,4,6

int main(){
    ll mod = 1000000007;
    ll N,ans,a;
    cin >> N;
    ll A[N+2];
    ll cnt[N+2];
    llrep(i,N+2){
        cnt[i] = 0;
    }
    llrep(i,N){
        cin >> a;
        cnt[a] ++;
    }
    if (N%2==0){//even
        for(ll i=1; i<=N-1; i+=2){
            if (cnt[i]!=2){
                cout << 0 << endl;
                return 0;
            }
        }
        ans = 1;
        llrep(i,N/2){
            ans *= 2;
            ans %= mod;
        }
        cout << ans << endl;
        return 0;
    }else{//odd
        if (N==1){
            if (cnt[0]==1){
                cout << 1 << endl;
                return 0;
            }else{
                cout << 0 << endl;
                return 0;
            }
        }else{
            if (cnt[0]!=1){
                cout << 0 << endl;
                return 0;
            }
            for(ll i=2; i<N; i+=2){
                if (cnt[i] != 2){
                    cout << 0 << endl;
                    return 0;
                }
            }
            ans = 1;
            llrep(i,N/2){
                ans *= 2;
                ans %= mod;
            }
            cout << ans << endl;
            return 0;
        }
    }

    return 0;
}

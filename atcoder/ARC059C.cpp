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


int main(){
    ll N, a;
    cin >> N;
    vector<ll> A;
    rep(i,N){
        cin >> a;
        A.push_back(a);
    }
    ll min_sum = INF;
    for(ll i=-100; i<=100; i++){
        ll sum = 0;
        rep(j,N){
            sum += ((A[j]-i)*(A[j]-i));
        }
        if (sum < min_sum) min_sum = sum;
    }
    cout << min_sum << endl;

    return 0;
}

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
    ll N;
    cin >> N;
    ll T[N+2],A[N+2],sum_min_T[N+2], min_T[N+2],sum_min_A[N+2], min_A[N+2];

    llRep(i,N){
        cin >> T[i] >> A[i];
    }
    sum_min_T[0] = 0;
    min_T[0] = 0;
    sum_min_A[0] = 0;
    min_A[0] = 0;

    llRep(i,N){
        sum_min_T[i] = max(T[i], min_T[i-1]);
        sum_min_A[i] = max(A[i], min_A[i-1]);

        ll multiply;
        if ((sum_min_T[i]/T[i]) * T[i] >= sum_min_T[i]){
            multiply = (sum_min_T[i]/T[i]);
        }else{
            multiply = (sum_min_T[i]/T[i])+1;
        }
        ll multiply2;
        if ((sum_min_A[i]/A[i]) * A[i] >= sum_min_A[i]){
            multiply2 = (sum_min_A[i]/A[i]);
        }else{
            multiply2 = (sum_min_A[i]/A[i])+1;
        }
            min_A[i] = A[i] * max(multiply,multiply2);
            min_T[i] = T[i] * max(multiply,multiply2);
    }

    cout << min_T[N] + min_A[N] << endl;


    return 0;
}

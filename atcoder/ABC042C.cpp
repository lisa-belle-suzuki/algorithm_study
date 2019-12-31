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


vector<int> D;

bool isHateNumberIncluded(int num){
    while(num>0){
        int rest = num%10;
        if (vector_finder(D, rest)) return true;
        num -= rest;
        num /= 10;
    }
    return false;
}


int main(){
    ll N,K;
    int d;
    cin >> N >> K;
    rep(i,K){
        cin >> d;
        D.push_back(d);
    }
    while(1){
        if (isHateNumberIncluded(N)/*嫌いな数字出現*/){
            N++;
        }else{
            break;
        }
    }
    cout << N << endl;

    return 0;
}

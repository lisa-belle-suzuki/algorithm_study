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
    int pay;
    cin >> pay;
    int back=1000-pay;
    int cnt=0;

    if (back>0){
        cnt += back/500;
        back -= 500*(back/500);
    }
    if (back>0){
        cnt += back/100;
        back -= 100*(back/100);
    }
    if (back>0){
        cnt += back/50;
        back -= 50*(back/50);
    }
    if (back>0){
        cnt += back/10;
        back -= 10*(back/10);
    }
    if (back>0){
        cnt += back/5;
        back -= 5*(back/5);
    }
    if (back>0){
        cnt += back;
    }

    cout << cnt << endl;

    return 0;
}

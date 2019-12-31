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

int count(string str, int cnt){
    if (str=="") return cnt;
    if (str.substr(0,5)=="tokyo" or str.substr(0,5)=="kyoto"){
        // cout << "aaa" << endl;
        cnt ++;
        str.erase(str.begin(), str.begin()+5);
        return count(str, cnt);
    }
    str.erase(str.begin(), str.begin()+1);
    // cout << "+1" << endl;
    return count(str, cnt);
}

int main(){
    int T,cnt;
    cin >> T;
    string S[102];
    rep(i,T) cin >> S[i];
    rep(i,T){
        cnt = count(S[i],0);
        cout << cnt << endl;
    }
    return 0;
}

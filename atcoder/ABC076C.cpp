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
    string S,T;
    cin >> S;
    cin >> T;
    int start=-1;
    rep(i,S.size()-T.size()+1){
        int cnt=0;
        rep(j,T.size()){
            if (S[i+j]!=T[j] && S[i+j]!='?') continue;
            else cnt ++;
            if (cnt == T.size()){
                start = i;
                break;
            }
        }
    }
    if (start==-1) cout << "UNRESTORABLE" << endl;
    else{
        rep(i,start){
            if (S[i]=='?') cout << 'a';
            else cout << S[i];
        }
        cout << T;
        for(int i=start+T.size(); i<S.size(); i++){
            if (S[i]=='?') cout << 'a';
            else cout << S[i];           
        }
        cout << "" << endl;
    }



    return 0;
}

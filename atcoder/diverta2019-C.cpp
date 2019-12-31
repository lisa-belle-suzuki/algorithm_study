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
    string s;
    string S[N+2];
    bool A_exist=false, B_exist=false;
    vector<ll> feature[5];//0:どっちもだめ、1:Aが末尾、2:Bがはじめ、3:Aが末尾かつBがはじめ
    ll cnt=0;
    llrep(i,N){
        cin >> s;
        S[i] = s;
        if(s[0]=='B'){
            if (s[s.size()-1]=='A'){
                feature[3].push_back(i);
            }else{
                feature[2].push_back(i);
            }
        }else{
            if (s[s.size()-1]=='A'){
                feature[1].push_back(i);
            }else{
                feature[0].push_back(i);
            }
        }
        llrep(j,s.size()-1){
            if (s[j]=='A' && s[j+1]=='B') cnt++;
        }
    }

    // cout << "cnt = " << cnt << endl;
    if (feature[3].size()>0){//ブロックあり
        cnt += (feature[3].size()-1);//ブロック
        if (feature[1].size()>0){
            if(feature[2].size()>0){
                cnt +=2;
                cnt += min(feature[1].size()-1, feature[2].size()-1);
            }else{
                cnt +=1;
            }
        }else{
            if (feature[2].size()>0){
                cnt +=1;
            }
        }
        // if (feature[1].size()>0){
        //     cnt ++;
        //     A_exist = true;
        // }
        // if (feature[2].size()>0){
        //     cnt ++;
        //     B_exist = true;
        // }
        // ll A_rest, B_rest;
        // if (A_exist){
        //     A_rest = feature[1].size()-1;
        // }else{
        //     A_rest = feature[1].size();
        // }
        // if (B_exist){
        //     B_rest = feature[2].size()-1;
        // }else{
        //     B_rest = feature[2].size();
        // }
        // if (feature[1].size()-1>0 && feature[2].size()-1>0){
        //     cnt += min(feature[1].size()-1, feature[2].size()-1);
        // }
    }else{//ブロックなし
        if (feature[1].size()>0 && feature[2].size()>0){
            cnt += min(feature[1].size(), feature[2].size());
        }
    }

    cout << cnt << endl;

    return 0;
}

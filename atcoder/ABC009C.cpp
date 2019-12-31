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
    int N,K;
    char c;
    vector<char> S,S_sorted,S_rest,S_rest_sorted;
    cin >> N >> K;
    bool used[N+2];
    rep(i,N+2){
        used[i] = false;
    }
    for(int i=0;i<N; i++){
        cin >> c;
        S.push_back(c);
    }
    copy(S.begin(), S.end(), back_inserter(S_sorted) );
    copy(S.begin(), S.end(), back_inserter(S_rest) );


    //ソート
    sort(S_sorted.begin(), S_sorted.end());

    if (K==N){
        rep(i,N){
            cout << S_sorted[i];
        }
        cout << "" << endl;
    }else{
        int cnt=0;
        rep(i,K/2){
            if (S[i]==S_sorted[i]) cnt ++;
        }
        // cout << "K/2よりも " << cnt << "回 多くできる"<< endl;

        int sorted_max_idx=K/2;
        while(cnt>0 && sorted_max_idx<N){
            if (S[sorted_max_idx]!=S_sorted[sorted_max_idx]){
                cnt --;
            }
            sorted_max_idx++;
        }
        //ソートした部分
        rep(j,sorted_max_idx){
            cout << S_sorted[j];
        }
        //ソートできていない部分
        rep(j,sorted_max_idx){
            for(int k=N-1; k>=0; k--){
                if (S_sorted[j]==S[k] && !used[k]) {
                    S_rest[k] = S[j];
                    used[k] = true;
                }
            }
        }

        // rep(i,N) cout << "used["<< i<<"] = " << used[i] << endl;
        // rep(i,N){
        //     if (i<sorted_max_idx){
        //         cout << S_sorted[i] << " ";
        //     }else{
        //         cout << S_rest[i] << " ";
        //     }
        // }
        // cout << "" << endl;

        if (K%2==1){//Kが奇数の場合
            bool flag = false;
            int idx=0;
            // cout << "sorted_max_idx = " << sorted_max_idx << endl;
            rep(i,N-sorted_max_idx){
                S_rest_sorted.push_back(S_rest[sorted_max_idx+i]);
            }
            // cout << S_rest_sorted.size() << endl;
            // copy(S.begin()+sorted_max_idx, S.end(), back_inserter(S_rest_sorted) );
            sort(S_rest_sorted.begin(), S_rest_sorted.end());
            // cout << "S_rest_sorted[idx] = " << S_rest_sorted[idx] << endl;
            // cout << "S_rest_sorted[idx+1] = " << S_rest_sorted[idx+1] << endl;
            // cout << "S_rest_sorted[idx+2] = " << S_rest_sorted[idx+2] << endl;
            // cout << "S_rest[sorted_max_idx+idx] = " << S_rest[sorted_max_idx+idx] << endl;
            // cout << "used[N-1]" << used[N-1] << endl;
            // cout << "S_rest[N-1] = " << S_rest[N-1] << endl;
            // cout << "S_rest_sorted[1] = " << S_rest_sorted[1] << endl;

            while (flag==false && idx<(N-sorted_max_idx)){
                if (S_rest[sorted_max_idx+idx] != S_rest_sorted[idx]){//S_rest[sorted_max_idx+idx]...左にいるでかいやつ
                    // cout << S_rest[sorted_max_idx+idx] <<"を小さくしたい" << endl;
                    for(int p=N-1; p> sorted_max_idx+idx; p--){
                        if((S_rest[p]==S_rest_sorted[idx]) && used[p]){//S_rest[p]...restのうち小さいやつ
                            char small = S_rest[p];
                            S_rest[p] = S_rest[sorted_max_idx+idx];
                            S_rest[sorted_max_idx+idx] = small;
                            used[p] = true;
                            used[sorted_max_idx+idx] = true;
                            flag = true;
                            break;
                        }
                    }
                }
                idx ++;
            }
        }
        for(int j=sorted_max_idx; j<N; j++){
            if (used[j]) cout << S_rest[j];
            else cout << S[j];
        }
        cout << "" << endl;

    }

    return 0;
}

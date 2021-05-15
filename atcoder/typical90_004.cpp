#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll A[2002][2002];
ll sum_row[2002];
ll sum_col[2002];


int main(){
    ll H,W;
    cin >> H >> W;
    for(ll i=0; i<H; i++){
        for(ll j=0; j<W; j++){
            cin >> A[i][j];
        }
    }
    // 各列の和を計算
    for(ll j=0; j<W; j++){
        ll sum = 0;
        for(ll i=0; i<H; i++){
            sum += A[i][j];
        }
        sum_col[j] = sum;
    }

    // 各行の和を計算
    for(ll i=0; i<H; i++){
        ll sum = 0;
        for(ll j=0; j<W; j++){
            sum += A[i][j];
        }
        sum_row[i] = sum;
    }

    // 答えを計算
    for(ll i=0; i<H; i++){
        for(ll j=0; j<W; j++){
            cout << sum_row[i]+sum_col[j]-A[i][j] << " ";
        }
        cout << "" << endl;
    }

    return 0;
}
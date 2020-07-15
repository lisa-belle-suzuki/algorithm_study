# include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int A[200002], B[200002];

int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    for(ll i=1; i<=N; i++){
        cin >> A[i];
    }
    for(ll j=1; j<=M; j++){
        cin >> B[j];
    }

    vector<ll> sumA_array, sumB_array;
    sumA_array.push_back(0); sumB_array.push_back(0);

    ll sumA = 0, sumB = 0, a, b;
    for(ll i=1; i<=N; i++){
        a = A[i];
        if (a > K) break;
        sumA += a;
        if (sumA > K) break;
        sumA_array.push_back(sumA);
    }
    for(ll j=1; j<=M; j++){
        b = B[j];
        if (b > K) break;
        sumB += b;
        if (sumB > K) break;
        sumB_array.push_back(sumB);
    }


    ll timeA, timeBmax;
    ll max_volume = 0;
    for(ll i=0; i<sumA_array.size(); i++){
        timeA = sumA_array[i];
        timeBmax = K - timeA;
        auto j = upper_bound(sumB_array.begin(), sumB_array.end(), timeBmax);
        max_volume = max(max_volume, i + (j - sumB_array.begin() - 1));
    }
    cout << max_volume << endl;
    return 0;
}
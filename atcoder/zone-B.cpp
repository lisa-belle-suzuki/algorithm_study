#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,D,H,d,h;


double necessary_h(ll d1, ll h){
    ll d2,h2;
    d2 = D - d1;
    h2 = H - h;
    double h1;
    h1 = (double)d1 * h2 / d2;
    return (double)(h - h1);
}

int main(){
    double ans=0.0;
    cin >> N >> D >> H;
    for(ll i=0; i<N; i++){
        cin >> d >> h;
        double new_max = necessary_h(d,h);
        if (ans < new_max){
            ans = new_max;
        }
    }
    cout << std::fixed << setprecision(4) << (double)ans << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

bool haveOkashi[102];

int main(){
    int N,K,d,a, cnt=0;
    cin >> N >> K;
    for(int i=0; i<K; i++){
        cin >> d;
        for(int j=0; j<d; j++){
            cin >> a;
            haveOkashi[a] = true;
        }
    }
    for(int i=1; i<=N; i++){
        if (haveOkashi[i]==false){
            cnt ++;
        }
    }
    cout << cnt << endl;
    return 0;
}
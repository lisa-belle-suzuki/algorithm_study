# include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;

int a[300002];
bool hasEaten[100002];
int maxYummy[100002];


int main(){
    int N, M;
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> a[i];
    }
    //最初の1個は1番が食べる
    cout << 1 << endl;
    hasEaten[1] = true;
    maxYummy[1] = a[0];
    // 残りの寿司について解く
    int start_j = 1;
    for(int i=1; i<M; i++){
        if (a[i-1] < a[i]){
            start_j = 1;
        }
        bool isSomeoneAte = false;
        for(int j=start_j; j<=N; j++){
            if (hasEaten[j]==false){
                cout << j << endl;
                isSomeoneAte = true;
                hasEaten[j] = true;
                maxYummy[j] = a[i];
                start_j = j+1;
                break;
            }else if (a[i] > maxYummy[j]){
                cout << j << endl;
                // cout << "original maxYummy = " << maxYummy[j];
                isSomeoneAte = true;
                maxYummy[j] = a[i];
                // cout << ", new maxYummy = " << maxYummy[j] << endl;
                start_j = j+1;
                break;
            }
        }
        if (isSomeoneAte==false) cout << -1 << endl;
    }

    return 0;
}
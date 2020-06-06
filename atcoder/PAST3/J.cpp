# include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;

int a[300002];
bool hasEaten[100002];
int maxYummy[100002];


bool solve(int i, int j){
    if (!hasEaten[j]){
        cout << j << endl;
        hasEaten[j] = true;
        maxYummy[j] = a[i];
        return true;
    }else if (a[i] > maxYummy[j]){
        cout << j << endl;
        maxYummy[j] = a[i];
        return true;
    }
    return false;
}

int main(){
    int N, M;
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> a[i];
    }

    for(int i=0; i<M; i++){
        bool hasSomeoneEaten = false;
        for(int j=1; j<=N; j++){
            if (solve(i, j)){
                hasSomeoneEaten = true;
                break;
            }
        }
        if (hasSomeoneEaten==false) cout << -1 << endl;
    }

    return 0;
}
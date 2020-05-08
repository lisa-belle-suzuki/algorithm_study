#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull A[200002];
unordered_map<ull, ull> I, J;
set<ull> X;

int main(){
    ull N;
    cin >> N;
    for(ull i=1; i<=N; i++){
        cin >> A[i];
        I[A[i] + i] += 1;
        J[i - A[i]] += 1;
        X.insert(A[i]+i);
    }

    ull cnt = 0;
    for(auto itr = X.begin(); itr!=X.end(); itr++){
        ull x = *itr;
        // cout << x << " " << I[x] << " "<< J[x]<< endl;
        cnt += I[x] * J[x];
    }

    cout << cnt << endl;

    return 0;
}
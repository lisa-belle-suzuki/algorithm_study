# include <bits/stdc++.h>

using namespace std;

int main(){
    string S,T;
    cin >> S >> T;
    int i=0, cnt=0;
    while(i<S.length()){
        if (S[i]!=T[i]) cnt ++;
        i++;
    }
    cout << cnt << endl;
    return 0;
}
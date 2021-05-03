#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    string S;
    cin >> S;
    int cnt = 0;
    for(int i=0; i<9; i++){
        if (S.substr(i, 4)=="ZONe"){
            cnt ++;
        }
    }
    cout << cnt << endl;
    return 0;
}
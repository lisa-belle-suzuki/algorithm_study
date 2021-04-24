#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int A,B,C;
    cin >> A >> B >> C;
    if(pow(A,2)+pow(B,2)<pow(C,2)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
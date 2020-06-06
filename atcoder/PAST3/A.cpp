# include<bits/stdc++.h>

using namespace std;



int main(){
    string S, T;
    cin >> S;
    cin >> T;
    if (S==T){
        cout << "same" << endl;
        return 0;
    }
    for (int i=0; i<3; i++){
        if (S[i]!=T[i] && tolower(S[i]) != tolower(T[i])){
            cout << "different" << endl;
            return 0;
        }
    }

    cout << "case-insensitive" << endl;

    return 0;
}
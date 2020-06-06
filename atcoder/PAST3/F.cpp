# include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

string S[501];

char same_char(string S1, string S2){
    for(int i=0; i<S1.size(); i++){
        for(int j=0; j<S2.size(); j++){
            if (S1[i]==S2[j]){
                return S1[i];
            }
        }
    }
    return ' ';
}

int main(){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> S[i];
    }
    if (N%2==0){
        string ans = "";
        for(int i=0; i<N/2; i++){
            char cur = same_char(S[i], S[N-1-i]);
            if (cur==' '){
                cout << -1;
                return 0;
            }else{
                ans += cur;
            }
        }
        for(int i=0; i<N/2; i++){
            cout << ans[i];
        }
        for(int i=0; i<N/2; i++){
            cout << ans[N/2-1-i];
        }
    }else{
        string ans = "";
        for(int i=0; i<N/2; i++){
            char cur = same_char(S[i], S[N-1-i]);
            if (cur==' '){
                cout << -1;
                return 0;
            }else{
                ans += cur;
            }
        }
        for(int i=0; i<N/2; i++){
            cout << ans[i];
        }
        cout << S[N/2][0];
        for(int i=0; i<N/2; i++){
            cout << ans[N/2-1-i];
        }
    }
    return 0;
}
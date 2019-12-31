# include <iostream>
# include <cmath>
# include <string>
# include <vector>

using namespace std;

bool canWin(string S, string T){
    for (int i=0; i< S.length(); i++){
        if (S[i]!=T[i]){
            if (S[i]=='@'){
                if (T[i] != 'a' && T[i] != 't' && T[i] != 'c' && T[i] != 'o' && T[i] != 'd' && T[i] != 'e' && T[i] != 'r'){
                    return false;
                }
            }else if (S[i]=='a' || S[i]=='t' || S[i]=='c' || S[i]=='o' || S[i]=='d' || S[i]=='e' || S[i]=='r'){
                if (T[i]!='@'){
                    return false;
                }
            }else{
                return false;
            }
        }
    }
    return true;
}

int main() {
    string s,t;
    cin >> s >> t;
    if (canWin(s,t)){
        cout << "You can win" << endl;
    }else{
        cout << "You will lose" << endl;
    }
    return 0;
}

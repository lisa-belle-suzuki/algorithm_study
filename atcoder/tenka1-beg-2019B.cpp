# include <algorithm>
# include <iostream>
# include <cmath>
# include <string>
# include <vector>

using namespace std;

int main() {
    int n,k;
    string S;
    cin >> n;
    cin >> S;
    cin >> k;
    char c = S[k-1];
    string sout="";
    for(int i=0; i<S.length(); i++){
        if (S[i]!=c){
            sout += '*';
        }else{
            sout += S[i];
        }
    }

    cout << sout << endl;

    return 0;
}

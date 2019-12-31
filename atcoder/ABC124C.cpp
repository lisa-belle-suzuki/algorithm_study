# include <algorithm>
# include <iostream>
# include <cmath>
# include <string>
# include <vector>

using namespace std;

int main() {
    string S;
    cin >> S;
    int blackOriginCount=0, whiteOriginCount=0;
    for (int i=0; i<S.size(); i++){
        if (i%2==0){
            if (S[i]=='0'){
                whiteOriginCount ++;
            }else{
                blackOriginCount ++;
            }
        }else{
            if (S[i]=='0'){
                blackOriginCount ++;
            }else{
                whiteOriginCount ++;
            }
        }
    }
    cout << min(blackOriginCount, whiteOriginCount) << endl;

    return 0;
}

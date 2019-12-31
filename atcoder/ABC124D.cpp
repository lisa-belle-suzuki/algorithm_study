# include <algorithm>
# include <iostream>
# include <cmath>
# include <string>
# include <vector>

using namespace std;

int main() {
    int N,K, count=0;
    string S;
    cin >> N >> K;
    cin >> S;

    vector<int> zeroInARow, oneInARow;
    for(int i=0; i<S.size(); i++){
        if (i==0 || S[i]==S[i-1]){
            count++;
        }else{
            if (S[i-1]=='0'){
                zeroInARow.push_back(count);
            }else{
                oneInARow.push_back(count);
            }
            count=1;
        }
    }

    return 0;
}

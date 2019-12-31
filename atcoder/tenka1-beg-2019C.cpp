# include <algorithm>
# include <iostream>
# include <cmath>
# include <string>
# include <vector>

using namespace std;

int main() {
    long long N;
    string S;
    cin >> N;
    cin >> S;

    vector<long long> blackSum;
    vector<long long> whiteSum;
    long long blackCount=0;
    long long whiteCount=0;

    for(long long i=0; i<N; i++){
        if (S[i]=='#'){
            blackCount ++;
        }else{
            whiteCount ++;
        }
        blackSum.push_back(blackCount);
        whiteSum.push_back(whiteCount);
    }

    vector<long long> numberOfFlips;
    for(long long i=0; i<N; i++){
        if(i==0){
            if (S[i]=='#'){
                numberOfFlips.push_back(whiteSum[N-1] - whiteSum[0]);
            }
        }else{
            if ( (S[i]=='#' && S[i-1]=='.') || (S[i]=='.' && S[i-1]=='#') || i==N-1 ){
                // cout << "i = " << i << "のとき " << blackSum[i-1] + (whiteSum[N-1] - whiteSum[i]) << endl;
                numberOfFlips.push_back( blackSum[i-1] + (whiteSum[N-1] - whiteSum[i]) );
            }
        }
    }
    // cout << blackSum[1] << endl;

    if (numberOfFlips.size()==0){
        cout << 0 << endl;
    }else{
        cout << *min_element(numberOfFlips.begin(), numberOfFlips.end()) << endl;
    }

    return 0;
}

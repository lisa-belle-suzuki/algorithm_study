# include <bits/stdc++.h>

using namespace std;

int sum = 0;

void res(int curSum, int curInt, string restStr){
    if (restStr.length()==0){
        cout << "+ " << (curSum + curInt) << endl;
        sum += (curSum + curInt);
        return;
    }
    cout << "cur " << curSum + curInt << " " << restStr.substr(1) << endl;
    res(curSum + curInt, stoi(restStr[0]), restStr.substr(1));
    cout << "cur " << curSum << " " << curInt * 10 <<  restStr.substr(1) << endl;
    res(curSum, curInt * 10 + stoi(restStr[0]), restStr.substr(1));
}


int main(){
    string S;
    cin >> S;
    res(0,stoi(S[0]),S.substr(1));
    cout << sum << endl;
    return 0;
}

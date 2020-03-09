# include <bits/stdc++.h>

using namespace std;

vector<string > result;

long long int numFromNumStr(string numStr){
    long long int ret = 0;
    long long int carrier = 1;
    while(!numStr.empty()){
        ret += atoi(&numStr[numStr.size()-1]) * carrier;
        carrier *= 10;
        numStr.pop_back();
    }
    return ret;
}


void solve(string done, string undone){
    if (undone.empty()){
        result.push_back(done);
        return;
    }
    solve(done + undone[0], undone.substr(1));
    solve(done + '+' + undone[0], undone.substr(1));
}


long long int numFromEquationString(string str){
    long long int num = 0;
    vector<int > idxList;
    vector<int > numList;
    idxList.push_back(-1);
    for (int i=0; i<str.length(); i++){
        if (str[i]=='+') idxList.push_back(i);
    }
    idxList.push_back(str.length());
    for (int i=0; i<idxList.size()-1; i++){
        num +=  numFromNumStr( str.substr(idxList[i]+1, idxList[i+1]-idxList[i] - 1) ) ;
    }
    return num;
}


int main(){
    string S;
    cin >> S;
    // cout << S.substr(1,2) << endl;
    // cout << S.substr(3) << endl;
    solve(S.substr(0,1), S.substr(1));
    long long int res = 0;
    for (int i=0; i<result.size(); i++){
        res += numFromEquationString(result[i]);
    }
    cout << res << endl;
    return 0;
}
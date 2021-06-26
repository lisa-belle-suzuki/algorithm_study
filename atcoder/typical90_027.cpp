#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

unordered_map<string, bool> dict;
string S[100002];
vector<int> nums;

int main(){
    ll N;
    string s;
    cin >> N;
    for(ll i=0; i<N; i++){
        cin >> s;
        if (dict.find(s) != dict.end()) continue;
        nums.push_back(i+1);
        dict[s] = true;
    }
    for(ll i=0; i<nums.size(); i++){
        cout << nums[i] << endl;
    }
    return 0;
}
# include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool solved[100002][51];
ll num_not_answer_people[51];

int main(){
    ll N, M, Q, num, n, m;
    cin >> N >> M >> Q;

    for(ll i=1; i<=M; i++){
        num_not_answer_people[i] = N;
    }

    vector<ll> output_num;
    for(ll i=0; i<Q; i++){
        cin >> num;
        if (num==1){
            cin >> n;
            ll score = 0;
            for(ll i=1; i<=M; i++){
                if (solved[n][i]){
                    score += num_not_answer_people[i];
                }
            }
            output_num.push_back(score);
        }else{
            cin >> n >> m;
            num_not_answer_people[m] --;
            solved[n][m] = true;
        }
    }

    for(ll i=0; i<output_num.size(); i++){
        cout << output_num[i] << endl;
    }

    return 0;
}
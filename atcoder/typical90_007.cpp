#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

vector<ll> A;
ll B[300002];

ll score(ll student_rating, ll class_rating){
    return abs(student_rating - class_rating);
}

ll min_unsatisfied_score(ll student_rating){
    ll l=0, r=A.size(),c;
    while(l<=r){
        c = (l+r)/2;
        if (c == A.size()-1){// 右端
            if (score(A[c],student_rating)<score(A[c-1],student_rating)){
                return score(A[c],student_rating);
            }else{
                r = c - 1;
            }
            continue;
        }

        if (score(A[c],student_rating)==score(A[c+1],student_rating)){
            return score(A[c],student_rating);
        }else if (score(A[c],student_rating)<score(A[c+1],student_rating)){
            r = c - 1;
        }else{
            l = c + 1;
        }
    }
    return score(A[l],student_rating);
}

int main(){
    ll N,Q,a;
    cin >> N;
    for(ll i=0; i<N; i++){
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());//重複を消す

    cin >> Q;
    for(ll i=0; i<Q; i++){
        cin >> B[i];
    }

    for(ll i=0; i<Q; i++){
        cout << min_unsatisfied_score(B[i]) << endl;
    }
    return 0;
}
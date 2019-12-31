# include <iostream>
# include <cmath>
# include <string>
# include <vector>

using namespace std;

int howManyACs(int l_id, int r_id, vector<int> ACposition){
    int count=0;
    for (int i=l_id; i<r_id; i++){
        count += ACposition[i];
    }
    return count;
}

int main() {
    int N, Q;
    string S;
    cin >> N >> Q;
    cin >> S;
    vector<int> ACpos(N+2, 0);
    vector<int> ACcount(N+2, 0);
    ACcount[0] = 0;
    // for (int i=1; i<N-1; i++){
    //     bool existAC = 0;
    //     if (S[i]=='A') {
    //         if (S[i+1]=='C') {
    //             existAC = 1;
    //             ACpos[i] = 1;
    //             if (i == 0) {
    //                 ACcount[i] = 1;
    //             }else{
    //                 ACcount[i+1] = ACcount[i] + 1;
    //             }
    //         }
    //     }
    //     if (!existAC) {
    //         if (i != 0) {
    //             ACcount[i+1] = ACcount[i];
    //         }
    //     }
    // }
    ACcount[N] = ACcount[N-1];
    for (int i=0; i<N; i++) {
        cout << "ACcount[ " << i <<  " ]= " << ACcount[i] << endl;
    }
    vector<int> l(N+2), r(N+2), counts(N+2);
    for (int i=0; i<Q; i++) {
        cin >> l[i] >> r[i];
        cout << ACcount[r[i]-1] - ACcount[l[i]-1] << endl;
        // cout << howManyACs(l[i]-1, r[i]-1, ACpos) << endl;
    //     counts[i] = howManyACs(l[i]-1, r[i]-1, ACpos);
    }
    // for (int i=0; i<Q; i++) {
        // cout << counts[i] << endl;
    // }
    return 0;
}

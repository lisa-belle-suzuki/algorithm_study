# include <algorithm>
# include <iomanip>
# include <iostream>
# include <cmath>
# include <string>
# include <vector>

using namespace std;

int main() {
    int n,k;
    long double r, movie_rate, score=0.0;
    cin >> n >> k;
    vector<long double> R;
    for (int i=0; i<n; i++){
        cin >> r;
        R.push_back(r);
    }
    sort(R.begin(), R.end());
    for (int i=0; i<k; i++){
        // cout << "+= " << R[n-k+i]; 
        movie_rate = R[n-k+i];
        score = (score + movie_rate) / 2.0000000;
        // cout << "score = " << fixed << setprecision(6) <<score << endl;
        // cout << "-----------" << endl;
    }
    cout << fixed << setprecision(6) << score << endl;

    return 0;
}

# include <iostream>
# include <string>
# include <vector>


using namespace std;

bool is_okay(int t_diff, int x_diff, int y_diff) {
    int rest = t_diff - (abs(x_diff) + abs(y_diff));
    if (rest >= 0) {
        if (rest % 2 == 0) {
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    vector<int> t(n+2);
    vector<int> x(n+2);
    vector<int> y(n+2);
    t[0] = 0;
    x[0] = 0;
    y[0] = 0;
    for (int i=1; i<n+1; i++) {
        cin >> t[i] >> x[i] >> y[i];
    }
    for (int i=0; i<n; i++) {
        int t_diff = t[i+1] - t[i];
        int x_diff = x[i+1] - x[i];
        int y_diff = y[i+1] - y[i];
        if (is_okay(t_diff, x_diff, y_diff) == false) {
            // cout << "i= " << i << endl;
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
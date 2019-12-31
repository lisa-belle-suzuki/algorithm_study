# include <iostream>
# include <string>
# include <vector>

using namespace std;

int main(){
    int m;
    string vv;
    cin >> m;
    if (m < 100) {
        vv = "00";
    }else if (m >= 100 && m <= 5000) {
        vv = to_string( m / 100 );
        if (vv.length() == 1) {
            vv = "0" + vv;
        }
    }else if (m >= 6000 && m <= 30000) {
        vv = to_string(m/1000 + 50);
    }else if (m >= 35000 && m <= 70000) {
        vv = to_string((m/1000 - 30)/5 + 80);
    }else if (m > 70000) {
        vv = "89";
    }
    cout << vv << endl;
    return 0;
}
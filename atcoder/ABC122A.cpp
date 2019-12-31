# include <iostream>
# include <cmath>
# include <string>
# include <vector>

using namespace std;

int main() {
    char n;
    cin >> n;
    if (n=='A') {
        cout << 'T' << endl;
    }else if (n=='T') {
        cout << 'A' << endl;
    }else if (n=='G') {
        cout << 'C' << endl;
    }else if (n=='C') {
        cout << 'G' << endl;
    }
    return 0;
}

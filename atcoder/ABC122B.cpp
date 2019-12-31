# include <iostream>
# include <cmath>
# include <string>
# include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int countMax=0;
    int countCur=0;
    // vector<int> notATGC(s.length()+2, -1);
    for (int i=0; i<s.length(); i++) {
        if (s[i]!='A' && s[i]!='T' && s[i]!='G' && s[i]!='C') {
            if (countCur > countMax) {
                countMax = countCur;
            }
            countCur=0;
            // notATGC.push_back(i);
        }else{
            countCur++;
        }
    }
    if (countCur > countMax) {
        countMax = countCur;
    }
    cout << countMax << endl;
    // if (notATGC[0]==-1) {
    //     cout << s.length() << endl;
    // }else{

    // }
    return 0;
}

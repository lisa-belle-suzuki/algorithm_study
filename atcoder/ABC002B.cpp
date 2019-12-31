# include <iostream>
# include <string>
# include <vector>

using namespace std;

int main(){
    string s, sout="";
    cin >> s;
    for (int i=0; i<s.length(); i++) {
        if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u') {
            sout += s[i];
        }
    }
    cout << sout << endl;
    return 0;
}
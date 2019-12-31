# include <iostream>
# include <string>

using namespace std;

bool solve(string s) {
    while(1) {
        if (s.length() == 0) {
            // cout << "aaa" << endl;
            return true;
        }
        if (s.length() < 5) {
            // cout << s << endl;
            // cout << "bbb" << endl;
            return false;
        }
        if (s.substr(0,5) == "erase") {
            if (s.substr(5,1)=="r") {
                s.erase(0,6); // eraser
            }else{
                s.erase(0,5); // erase
            }
        } else if (s.substr(0,5) == "dream") {
            if (s.substr(5,3) == "erd" || s.substr(5,3) == "ere") {
                s.erase(0,7); // dreamer
            }else if(s.length() == 7 && s.substr(0,7)== "dreamer"){
                s.erase(0,7); // dreamer
            }else{
                s.erase(0,5); // dream
            }
        } else {
            // cout << "ccc" << endl;
            return false;
        }
    }
    // cout << "ERROR" << endl;
    return false;
}

int main(){
    string s;
    cin >> s;
    if (solve(s)) {
        cout << "YES" << endl;
        return 0;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
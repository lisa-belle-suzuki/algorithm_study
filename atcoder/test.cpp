# include <iostream>

using namespace std;

int main(){
    int i;
    while(cin >> i){
        if(std::cin.eof()) break;
        cout << i;
    }
    return 0;
}
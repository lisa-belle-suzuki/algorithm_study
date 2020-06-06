# include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<string> S;
vector<string> mihon;
vector<string> num_string;
vector<string> S_;

int which_num(string numS){
    for(int i=0; i<10; i++){
        if (numS==num_string[i]){
            return i;
        }
    }
    return INT_MAX;
}

int main(){

    mihon.push_back(".###..#..###.###.#.#.###.###.###.###.###.");
    mihon.push_back(".#.#.##....#...#.#.#.#...#.....#.#.#.#.#.");
    mihon.push_back(".#.#..#..###.###.###.###.###...#.###.###.");
    mihon.push_back(".#.#..#..#.....#...#...#.#.#...#.#.#...#.");
    mihon.push_back(".###.###.###.###...#.###.###...#.###.###.");

    int N;
    for(int i=0; i<10; i++){
        string sum = "";
        for(int j=0; j<5; j++){
            sum += mihon[j].substr(4 * i, 4);
        }
        num_string.push_back(sum);
    }
    cin >> N;
    string s;
    for(int i=0; i<5; i++){
        cin >> s;
        S.push_back(s);
    }
    for(int i=0; i<N; i++){
        string sum = "";
        for(int j=0; j<5; j++){
            sum += S[j].substr(4 * i, 4);
        }
        S_.push_back(sum);
    }
    for(int i=0; i<N; i++){
        cout << which_num(S_[i]);
    }

    return 0;
}
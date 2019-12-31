# include <iostream>
# include <cmath>
# include <map>
# include <string>
# include <vector>

using namespace std;

int main() {
    int N,q;
    string s;
    cin >> N >> q;
    cin >> s;
    vector<char> t(q+2), d(q+2);
    for (int i=1; i<=q; i++){
        cin >> t[i] >> d[i];
    }

    int originalGorem = N;
    map<char, vector<int> > char2position;
    for (int i=0; i<N; i++){
        char2position[s[i]].push_back(i);
    }

    vector<int>goremCount (N, 1);

    // [1,1,1]
    // [0,1,1]

    int goneGorem = 0;
    for (int i=1; i<=q; i++){
        vector<int> position = char2position[t[i]];
        for (int j=0; j<position.size(); j++){
            int pos = position[j];
            if (pos == 0 && d[i] == 'L') {
                goneGorem += goremCount[pos];
                goremCount[pos] = 0;
            }else if (pos == N-1 && d[i] == 'R') {
                goneGorem += goremCount[pos];
                goremCount[pos] = 0;
            }else{
                if (d[i] == 'L'){
                    goremCount[pos-1] += goremCount[pos];
                    goremCount[pos] = 0;
                }else{
                    goremCount[pos+1] += goremCount[pos];
                    goremCount[pos] = 0;
                }
            }
        }
    }
    cout << N - goneGorem << endl;
    // for 全てのtとd:
        // char2positionでマスを指定
        // if そのマスが0でLなら、ゴーレムが消滅（goremCountのそのマスについての数が0になる）
        // if そのマスがN-1でRなら、ゴーレムが消滅（goremCountのそのマスについての数が0になる）
        // else それ以外なら、そのマスのゴーレムが、隣のマスに移る（goremCountのそのマスについての数が、隣のマスのcountに移る）
    // 最後に全てのマスのgoremCountを足し合わせる O(N)


    return 0;
}

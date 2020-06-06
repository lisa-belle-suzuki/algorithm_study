# include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

using Graph = vector<vector<int>>;

int N, X, Y, x, y, o_x, o_y;
bool isObstacle[402][402];
bool visited[402][402];

int min_iter = INT_MAX;
void search(int cur_iter, int x, int y){

}

int main(){
    cin >> N >> X >> Y;
    X += 200; Y+= 200;
    for(int i=0; i<N; i++){
        cin >> o_x >> o_y;
        isObstacle[200 + o_x][200 + o_y] = true;
    }
    cout << X << endl;
    cout << Y << endl;
    search(0, 200, 200);

    if (min_iter==INT_MAX){
        cout << -1 << endl;
    }else{
        cout << min_iter << endl;
    }
    return 0;
}
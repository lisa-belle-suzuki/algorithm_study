class Solution {
public:
    int uniquePaths(int m, int n) {
        int ret[100][100] = {0};
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if (i==0) ret[i][j] = 1;
                else if (j==0) ret[i][j] = ret[i-1][j];
                else ret[i][j] = ret[i-1][j] + ret[i][j-1];
            }
        }
        return ret[m-1][n-1];
    }
};
class Solution {
public:
    unsigned long long uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        bool isObstacle = false;
        unsigned long long ret[100][100] = {}; // overflowしたのでunsigned long longにしたら通ったw
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                isObstacle = false;
                if (obstacleGrid[i][j]==1) isObstacle = true;
                if (i==0){
                    if (isObstacle) ret[i][j] = 0;
                    else{
                        if (j==0) ret[i][j] = 1;
                        else ret[i][j] = ret[i][j-1];
                    }
                }else{
                    if (j==0){
                        if (isObstacle) ret[i][j] = 0;
                        else ret[i][j] = ret[i-1][j];
                    }else{
                        if (isObstacle) ret[i][j] = 0;
                        else ret[i][j] = ret[i-1][j] + ret[i][j-1];
                    }
                }
            }
        }
        return ret[m-1][n-1];
    }
};
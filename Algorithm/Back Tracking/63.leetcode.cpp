#include <bits/stdc++.h>

using namespace std;

pair<int, int> operator +(const pair<int, int>&x, const pair<int, int> &y){
    return make_pair(x.first + y.first, x.second + y.second);
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if(obstacleGrid[0][0] == 1){
        return 0;
    }
    obstacleGrid[0][0] = 1;
    for(int j = 1; j < n; j++){
        if(obstacleGrid[0][j] == 1){
            obstacleGrid[0][j] = 0;
        }
        else{
            obstacleGrid[0][j] = obstacleGrid[0][j-1];
        }
    }
    for(int i = 1; i < m; i++){
        if(obstacleGrid[i][0] == 1){
            obstacleGrid[i][0] = 0;
        }
        else{
            obstacleGrid[i][0] = obstacleGrid[i-1][0];
        }
    }
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(obstacleGrid[i][j] == 1){
                obstacleGrid[i][j] = 0;
            }
            else{
                obstacleGrid[i][j] = obstacleGrid[i][j-1] + obstacleGrid[i-1][j];
            }
        }
    }
    return obstacleGrid[m-1][n-1];
}



int main(){
    vector<vector<int>> obs = vector<vector<int>> {{0, 1}, {0, 0}};
    cout << uniquePathsWithObstacles(obs);
}







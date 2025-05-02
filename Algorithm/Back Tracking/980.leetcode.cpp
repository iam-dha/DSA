// Unique Paths 3
#include <bits/stdc++.h>

using namespace std;
int ans;
int n, m, block_num;
vector<vector<int>> way;
bool visited [21][21];

bool check(int x, int y, vector<vector<int>>& grid){
    if(x < 0 || y < 0 || x >= m || y >= n || visited[x][y] || grid[x][y] == -1){
        return false;
    }
    else{
        return true;
    }

}

void backtrack(int x, int y, vector<vector<int>>& grid, int step){
    for(int i = 0; i < 4; i++){
        vector<int> direction = way[i];
        int new_x = x + direction[0];
        int new_y = y + direction[1];
        if(check(new_x, new_y, grid)){
            visited[new_x][new_y] = true;
            if(grid[new_x][new_y] == 2 ){
                if(step == block_num + 1){
                    ans++;
                }
            }
            else{
                backtrack(new_x, new_y, grid, step + 1);
            }
            visited[new_x][new_y] = false;
        }
    }
}

int uniquePathsIII(vector<vector<int>>& grid) {
    way = vector<vector<int>> {{1, 0}, {0, -1}, {-1, 0}, {0, 1} };
    ans = 0;
    m = grid.size();
    n = grid[0].size();
    block_num = n * m - 1;
    int x, y;
    bool flag = true;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1){
                x = i;
                y = j;
                block_num--;
            }
            else if(grid[i][j] == -1){
                block_num--;
            }
        }
    }
    visited[x][y] = true;
    backtrack(x, y, grid, 1);
    return ans;
}


int main(){
    vector<vector<int>> temp = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    cout << uniquePathsIII(temp);
}





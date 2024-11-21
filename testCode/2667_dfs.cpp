#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> map;
vector<vector<bool>> visited;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int dfs(int x, int y){
    visited[x][y] = true;
    int count =1;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx>=0 && nx<N && ny>=0 && ny < N){
            if(map[nx][ny]==1 && !visited[nx][ny]){
                count += dfs(nx, ny);
            }
        }
    }
    return count;
}


int main(void){
    cin >> N;
    map.resize(N, vector<int> (N));
    visited.resize(N, vector<bool> (N, false));

    //input
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            char c;
            cin >> c;
            map[i][j] = c-'0';
        }
    }
    vector<int> answers;

    for(int i=0; i<N; i++){
        for(int j=0;j<N; j++){
            if(map[i][j]==1 && !visited[i][j]){
                answers.push_back(dfs(i,j));
            }
        }
    }

    sort(answers.begin(), answers.end());
    cout << answers.size() << '\n';
    for(int ans : answers){
        cout << ans << '\n';
    }
    return 0;
}
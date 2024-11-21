#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
vector<vector<int>> map;
vector<vector<bool>> visited;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


int bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x,y});
    visited[x][y] = true;

    int count = 1;
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx>=0 && nx<N && ny>=0 && ny <N){
                if(map[nx][ny]==1 && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    count ++;
                }
            }
        }
    }
    return count;
}

int main(void){
    cin >> N;
    map.resize(N, vector<int> (N));
    visited.resize(N, vector<bool> (N, false));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            char c;
            cin >> c;
            map[i][j] = c-'0';
        }
    }

    vector<int> answers;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j]==1 && !visited[i][j]){
                answers.push_back(bfs(i,j));
            }
        }
    }

    sort(answers.begin(), answers.end());
    cout << answers.size() << "\n";
    for(int ans : answers){
        cout << ans << "\n";
    }
    return 0;
}
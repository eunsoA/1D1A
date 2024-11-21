#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_block = 0;

vector<vector<int>> move(vector<vector<int>> board, int direction){
    int N = board.size();
    vector<vector<int>> new_board(N, vector<int>(N,0));

    if(direction == 0){
        for(int j=0; j<N; j++){
            int idx = 0;
            int prev = 0;
            for(int i=0; i<N; i++){
                if(board[i][j]==0) continue;
                if(prev == 0){
                    prev = board[i][j];
                } else if(prev == board[i][j]){
                    new_board[idx++][j] = prev*2;
                    prev = 0;
                } else {
                    new_board[idx++][j] = prev;
                    prev = board[i][j];
                }
            }
        }
    }
}


void dfs(vector<vector<int>> board, int depth){
    if(depth == 5){
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board.size(); j++){
                max_block = max(max_block, board[i][j]);
            }
        }
        return;
    }

    for(int dir = 0; dir <4; dir++){
        vector<vector<int>> next_board = move(board,dir);
        if(next_board != board){
            dfs(next_board, depth+1);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> board(N, vector<int> (N));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> board[i][j];
        }
    }

    dfs(board, 0);

    cout << max_block << "\n";
    return 0;
}
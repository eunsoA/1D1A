#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp(vector<vector<int>> &D, vector<vector<int>> &V, int i, int j, int N) {
    V[i][j] = 1; // 방문 처리
    int count = 1;

    // 상하좌우 탐색
    if ((i - 1) >= 0 && D[i - 1][j] == 1 && V[i - 1][j] == 0) { // up
        count += dp(D, V, i - 1, j, N);
    }
    if ((j + 1) < N && D[i][j + 1] == 1 && V[i][j + 1] == 0) { // right
        count += dp(D, V, i, j + 1, N);
    }
    if ((i + 1) < N && D[i + 1][j] == 1 && V[i + 1][j] == 0) { // down
        count += dp(D, V, i + 1, j, N);
    }
    if ((j - 1) >= 0 && D[i][j - 1] == 1 && V[i][j - 1] == 0) { // left
        count += dp(D, V, i, j - 1, N);
    }

    return count;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> D(N, vector<int>(N));
    vector<vector<int>> V(N, vector<int>(N, 0)); // 방문 여부 초기화
    vector<int> answer;

    // 행렬 입력
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        
        for (int j = 0; j < N; j++) {
            D[i][j] = row[j] - '0'; //문자를 숫자로 변환
        }
    }

    // 단지 탐색
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (D[i][j] == 1 && V[i][j] == 0) {
                answer.push_back(dp(D, V, i, j, N));
            }
        }
    }

    // 결과 출력
    cout << answer.size() << "\n";
    sort(answer.begin(), answer.end());
    for (int count : answer) {
        cout << count << "\n";
    }
    return 0;
}

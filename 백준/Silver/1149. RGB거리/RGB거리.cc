#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int dp(vector<vector<int>> &RGB, vector<vector<int>> &memo, int N, int pre, int nCount) {
    if (nCount == N) { // 종료 조건: 모든 집을 칠했을 때
        return 0;
    }

    if (memo[pre][nCount] != -1) { // 메모이제이션: 이미 계산된 경우
        return memo[pre][nCount];
    }

    // 현재 색깔의 비용 계산
    int count = RGB[pre][nCount];
    count += min(
        dp(RGB, memo, N, (pre + 1) % 3, nCount + 1), // 다음 집은 다른 색으로 칠함
        dp(RGB, memo, N, (pre + 2) % 3, nCount + 1)  // 다음 집은 다른 색으로 칠함
    );

    memo[pre][nCount] = count; // 결과 저장
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // RGB 비용 입력
    vector<vector<int>> RGB(3, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> RGB[j][i];
        }
    }

    // 메모이제이션 배열 초기화
    vector<vector<int>> memo(3, vector<int>(N, -1));

    // 최소 비용 계산
    int mincount = INT_MAX;
    for (int i = 0; i < 3; i++) {
        mincount = min(mincount, dp(RGB, memo, N, i, 0));
    }
    cout << mincount << "\n";

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    // 최대 40까지의 피보나치 호출 횟수를 미리 계산하여 저장
    int dp[41][2] = { {1, 0}, {0, 1} }; // dp[i][0] = fibonacci(i)에서 0의 호출 횟수, dp[i][1] = fibonacci(i)에서 1의 호출 횟수

    for (int i = 2; i <= 40; ++i) {
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
    }

    while (T--) {
        int n;
        cin >> n;
        cout << dp[n][0] << " " << dp[n][1] << endl;
    }

    return 0;
}

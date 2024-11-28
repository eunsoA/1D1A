#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MOD = 1e9; // max number

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;//합이 n이 돼
    int K;//k개의 숫자로

    cin >> N >> K;
    
    vector<vector <int>> dp(K+1, vector<int>(N+1, 0)); // dp[i][j] == i개의 숫자로 j를 만드는 경우의수

    for(int i=0; i <= K; i++){
        dp[i][0] = 1;   // 합이 0 이 되는 경우 1가지
    }

    for(int i=1; i<=K; i++){
        for(int j =1; j<=N; j++){
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }

    cout << dp[K][N];

    return 0;
}
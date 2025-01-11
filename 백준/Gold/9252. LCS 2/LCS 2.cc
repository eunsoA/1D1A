#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string A, B;
    cin >> A >> B;

    int n = A.size();
    int m = B.size();

    // dp 배열 초기화
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    //dp 점화식 계산
    for(int i=1; i<=n; i++){
        for(int j =1; j<=m; j++){
            if(A[i-1] == B[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // lcs 길이 출력
    cout << dp[n][m]<<"\n";

    if(dp[n][m]!=0){
        //lcs 복원
        string lcs = "";
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (A[i - 1] == B[j - 1]) {
                lcs += A[i - 1]; // 공통 문자를 LCS에 추가
                i--;
                j--;
            } else if (dp[i - 1][j] >= dp[i][j - 1]) {
                i--; // 위쪽으로 이동
            } else {
                j--; // 왼쪽으로 이동
            }
        }

        // LCS 문자열 출력 (역순이므로 뒤집기)
        reverse(lcs.begin(), lcs.end());
        cout << lcs << "\n";
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    const int MAX_N = 10000;
    vector<vector<int>> dp(MAX_N + 1, vector<int>(4, 0));
    
    for(int i=1; i<=3; i++){
        dp[0][i] = 1;
    }

    for(int i=1; i<=MAX_N; i++){
        for(int j=1; j<=3; j++){
            dp[i][j] = dp[i][j-1]; //j를 사용하지 않은 경우
            if(i>=j){
                dp[i][j] += dp[i-j][j];//j를 사용한경우
            }
        }
    }
    
    while(T--){
        int n;
        cin >> n;
        cout << dp[n][3] << "\n";
    }

    return 0;
}
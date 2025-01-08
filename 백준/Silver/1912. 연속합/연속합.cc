#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin>>N;

    vector<int> num(N + 1, 0);
    vector<int> dp(N + 1, 0);

    //input and initialization
    for(int i=1; i<=N; i++){
        cin >> num[i];
    }
    
    dp[1] = num[1];
    int maxSum = dp[1];

    // dynamic programming
    for(int i=2; i<=N; i++) {
        dp[i] = max(dp[i-1]+num[i], num[i]);
        maxSum = max(maxSum, dp[i]); // 최대값 업데이트
    }
    
    // 결과 출력
    cout << maxSum << "\n";
    
    return 0;
}
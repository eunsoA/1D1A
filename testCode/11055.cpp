#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(N, 0);
    vector<int> dp(N, 1); // DP 배열 초기화

    // 입력
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        dp[i] = arr[i];
    }

    // DP 점화식 계산
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }
    
    int result = *max_element(dp.begin(), dp.end());
    cout << result << "\n";

    return 0;
}
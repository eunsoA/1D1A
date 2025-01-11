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
    vector<int> dp(N, 1); // DP 배열: 길이 저장
    vector<int> prev(N, -1); // 이전 원소의 인덱스 저장 (-1은 시작점)

    // 입력
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // DP 점화식 계산
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[i] < dp[j]+1) {
                dp[i] = max(dp[i], dp[j] + 1);
                prev[i] = j; // 이전 원소의 인덱스 저장
            }
        }
    }

    // 가장 긴 증가하는 부분 수열의 길이와 마지막 인덱스 찾기
    int maxLength = 0, lastIndex = 0;
    for (int i = 0; i < N; i++) {
        if (dp[i] > maxLength) {
            maxLength = dp[i];
            lastIndex = i;
        }
    }

    // 결과 출력: 길이
    cout << maxLength << "\n";

    
    // 수열 복원
    vector<int> lis;
    for(int i=lastIndex; i!=-1; i=prev[i]){
        lis.push_back(arr[i]);
    }
    reverse(lis.begin(), lis.end()); //역순 수열 뒤집기

    // 수열 출력
    for(int i=0; i<lis.size(); i++){
        cout << lis[i] << " ";
    }
    cout << "\n";

    return 0;
}
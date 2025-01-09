#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin>>N;

    vector<int> arr(N,0);
    vector<int> dp(N,1);

    // 입력
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }


    //점화식
    for(int i=1; i<N; i++){
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    int result = *max_element(dp.begin(), dp.end());
    cout << result << "\n";
    return 0;
}
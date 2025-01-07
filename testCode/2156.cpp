#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> wine(N, 0);
    vector<int> dp(N, 0);
    for(int i=0; i<N; i++){
        cin >> wine[i];
    }

    dp[0] = wine[0];
    dp[1] = wine[0] + wine[1];

    for(int i=2; i<N; i++){
        dp[i] = max({dp[i-1], dp[i-2]+wine[i], dp[i-3]+wine[i-1]+wine[i]});
    }

    cout << dp[N-1]<<"\n";

    return 0;
}
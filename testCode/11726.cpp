#include <iostream>
#include <vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> dp(n+1, 0);

    dp[1]=1;
    if(n>1){
        dp[2] =2;
    }
    for(int i=3; i<n+1; i++){
        dp[i] = (dp[i-1]+dp[i-2])%10007;
    }
    cout<<dp[n]<<"\n";

    return 0;
}
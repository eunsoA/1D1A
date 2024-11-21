#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string A, B;
    cin>>A>>B;

    int m = A.size();
    int n = B.size();

    vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
    
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(A[i-1] == B[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[m][n] << "\n";
    
    return 0;
}
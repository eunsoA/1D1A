#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int dp(vector<vector<int>> &RGB, vector<vector <int>> &memo, int N, int pre, int nCount){
    if(nCount == N)
        return 0;
    
    if(memo[pre][nCount] != -1)
        return memo[pre][nCount];
    
    int count = RGB[pre][nCount];
    count += min(
        dp(RGB, memo, N, (pre+1)%3, nCount+1),
        dp(RGB, memo, N, (pre+2)%3, nCount+1)
    );
    memo[pre][nCount] = count;
    return count;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // RGB input
    vector<vector<int>> RGB(3, vector<int> (N));

    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            cin >> RGB[j][i];
        }
    }

    // memo
    vector<vector<int>> memo(3, vector<int> (N, -1));

    // 
    int mincount = INT_MAX;
    for(int i=0; i<3; i++){
        mincount = min(mincount, dp(RGB, memo, N, i, 0));
    }
    cout << mincount << "\n";

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    
    vector<int> leftDp(N, 1);
    vector<int> rightDp(N, 1);

    for(int i=1; i<N; i++){
        for(int j=0; j<i; j++){
            if(A[i]>A[j]){
                leftDp[i] = max(leftDp[i], leftDp[j]+1);
            }
        }
    }

    for(int i=N-2; i>=0; i--){
        for(int j=N-1; j>i; j--){
            if(A[i]>A[j]){
                rightDp[i] = max(rightDp[i], rightDp[j]+1);
            }
        }
    }

    int maxOutput = 0;
    for(int i=0;i<N;i++){
        maxOutput = max(maxOutput, leftDp[i] + rightDp[i]-1);
    }
    cout << maxOutput << "\n";
    return 0;
}
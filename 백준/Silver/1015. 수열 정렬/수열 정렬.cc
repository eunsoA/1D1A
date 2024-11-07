#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> A(n); // (값, 원래 인덱스) 쌍을 저장
    vector<int> P(n); // 결과 배열

    for (int i = 0; i < n; ++i) {
        cin >> A[i].first;
        A[i].second = i; // 원래 인덱스 저장
    }

    // 값 기준으로 정렬
    sort(A.begin(), A.end());

    // P 배열에 정렬된 인덱스를 할당
    for (int i = 0; i < n; ++i) {
        P[A[i].second] = i;
    }

    // P 배열 출력
    for (int i = 0; i < n; ++i) {
        cout << P[i] << " ";
    }

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    long long N;
    int L;
    cin >> N >> L;

    for (int len = L; len <= 100; len++) {
        long long temp = (len * (len - 1)) / 2;
        
        // x가 정수인지 확인하기 위해 (N - temp)가 len으로 나누어 떨어지는지 검사
        if (N >= temp && (N - temp) % len == 0) {
            long long x = (N - temp) / len;
            if (x >= 0) {
                // 연속된 수열 출력
                for (int i = 0; i < len; i++) {
                    cout << x + i << " ";
                }
                cout << endl;
                return 0;
            }
        }
    }

    // 길이가 100을 넘는 수열을 찾지 못한 경우
    cout << "-1" << endl;
    return 0;
}

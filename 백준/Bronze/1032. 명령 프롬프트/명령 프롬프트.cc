#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> filenames(n);
    for (int i = 0; i < n; i++) {
        cin >> filenames[i];
    }

    // 첫 번째 파일 이름을 기준으로 패턴을 만듦
    string pattern = filenames[0];

    // 다른 파일들과 비교하여 패턴 수정
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < pattern.size(); j++) {
            // 문자가 다르면 '?'로 대체
            if (pattern[j] != filenames[i][j]) {
                pattern[j] = '?';
            }
        }
    }

    // 결과 출력
    cout << pattern << endl;

    return 0;
}

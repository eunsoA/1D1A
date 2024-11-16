#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double A, B;
    cin >> A >> B;
    
    // A를 B로 나눈 결과를 소수점 이하 9자리까지 출력
    cout << fixed << setprecision(9) << A / B << endl;
    
    return 0;
}

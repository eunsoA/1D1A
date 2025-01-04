#include <iostream>
#include <string>

using namespace std;

int main(void) {
    while(1){
        int A, B;
        cin >> A >> B;
        if(A == 0 && B == 0){
            return 0;
        }
        cout << A+B <<"\n";
    }
    return 0;
}
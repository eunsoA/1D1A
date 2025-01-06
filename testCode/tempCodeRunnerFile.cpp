#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    vector<int> dp0(41, 0);
    vector<int> dp1(41, 0);

    dp0[0] = 1;
    dp1[0] = 0;
    dp0[1] = 0;
    dp1[1] = 1;
    for(int i=3; i<41; i++){
        dp0[i] = dp0[i-1] + dp0[i-2];
        dp1[i] = dp1[i-1] + dp1[i-2];
    }

    while (T--)
    {
        int N;
        cin >> N;
        cout << dp0[N] << " " << dp1[N] << "\n";
    }

    return 0;
}
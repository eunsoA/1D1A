#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int N;
    cin >> N;
    
    vector<pair<int, int>> wires(N);
    for(int i=0; i<N; i++){
        cin >> wires[i].first >> wires[i].second;
    }

    //A 기준 정렬
    sort(wires.begin(), wires.end());

    vector<int> lis;
    for(int i=0; i< N; i++){
        int b_position = wires[i].second;

        auto it = lower_bound(lis.begin(), lis.end(), b_position);
        if(it == lis.end()){
            lis.push_back(b_position); //insert new position
        } else {
            *it = b_position; //update position
        }
    }

    int lis_length = lis.size();
    cout << N - lis_length << "\n";
    return 0;
}
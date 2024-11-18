#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;//지폐 접을 횟수
    
    while(1){
        // 지갑에 들어가는지 체크
        if((max(wallet[0],wallet[1]) >= max(bill[0],bill[1])) 
           && (min(wallet[0],wallet[1]) >= min(bill[0],bill[1]))){
            break;
        } else {
            // 접고 answer +1 넘김
            if(bill[0]>bill[1])
                bill[0] = bill[0]/2;
            else
                bill[1] = bill[1]/2;
            answer ++;
        }
    }    
    return answer;
}
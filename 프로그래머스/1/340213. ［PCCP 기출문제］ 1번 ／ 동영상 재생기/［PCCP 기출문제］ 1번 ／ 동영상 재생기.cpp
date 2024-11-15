#include <iostream>
#include <string>
#include <vector>

using namespace std;

int toSeconds(const string time){
    int min = stoi(time.substr(0,2));
    int sec = stoi(time.substr(3,2));
    return min * 60 + sec;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    // string to int 
    int videoLen = toSeconds(video_len);
    int currentPos = toSeconds(pos);
    int opStart = toSeconds(op_start);
    int opEnd = toSeconds(op_end);
    
    for (int i=0; i<commands.size(); i++){
        if(currentPos <= opEnd && currentPos >= opStart){
            currentPos = opEnd;
        }
        
        if(commands[i] == "prev"){
            currentPos -= 10;
            if(currentPos < 0) currentPos = 0;
        } else if(commands[i] == "next") {
            currentPos += 10;
            if (currentPos > videoLen) currentPos = videoLen;
        }
    }
    
    
    if(currentPos <= opEnd && currentPos >= opStart){
        answer = op_end;
    } else if (currentPos == 0){
        answer = "00:00";  
    } else {
        int min = currentPos / 60;
        int sec = currentPos % 60;
        if(min<10){
            answer += "0";
        }
        answer += to_string(min);
        answer += ":";
        if(sec<10){
            answer += "0";
        }
        answer += to_string(sec);
    }
    
    return answer;
}
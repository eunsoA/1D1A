function solution(numbers, target) {
    let answer = 0;
    getAnswer(0,0);
    
    function getAnswer(index,value) {
        if(index<numbers.length){
            getAnswer(index+1,value + numbers[index]);
            getAnswer(index+1,value - numbers[index]);
        } else{
            if(value === target){
                answer++
            }
        }
    }
    return answer;
}
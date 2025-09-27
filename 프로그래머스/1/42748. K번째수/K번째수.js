function solve(arr, i, j, k){
    const tmpArr = arr.slice(i-1,j);
    tmpArr.sort((a,b)=> a-b);
    return tmpArr[k-1];
}

function solution(array, commands) {
    let answer = [];
    commands.map((command) => {
        const tmp = solve(array, command[0], command[1], command[2]);
        answer.push(tmp);
    });
    return answer;
}
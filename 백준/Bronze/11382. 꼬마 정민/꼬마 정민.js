const fs = require('fs');

// 입력 받기
const input = fs.readFileSync('/dev/stdin').toString().trim().split(' ');

// 입력된 값을 숫자로 변환하여 더하기
const result = input.reduce((sum, num) => sum + Number(num), 0);

// 결과 출력
console.log(result);

const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split(' ');

// 각 숫자를 뒤집음
const reversedA = input[0].split('').reverse().join('');
const reversedB = input[1].split('').reverse().join('');

// 문자열을 숫자로 바꾸고 비교
const numA = parseInt(reversedA);
const numB = parseInt(reversedB);

console.log(Math.max(numA, numB));

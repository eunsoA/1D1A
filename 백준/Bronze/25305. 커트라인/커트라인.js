const fs = require('fs');

// 입력을 받기 위한 코드 (백준 환경에서는 '/dev/stdin' 사용)
const input = fs.readFileSync('/dev/stdin', 'utf8').trim().split('\n');

// 첫 번째 줄에서 n과 k 값을 가져옴
const [n, k] = input[0].split(' ').map(Number);

// 두 번째 줄에서 점수 배열을 가져와 정수 배열로 변환
const scores = input[1].split(' ').map(Number);

// 점수를 내림차순 정렬
scores.sort((a, b) => b - a);

// k번째 점수를 출력
console.log(scores[k - 1]);
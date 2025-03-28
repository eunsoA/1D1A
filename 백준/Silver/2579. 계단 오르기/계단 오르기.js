const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

// 입력 처리
const n = parseInt(input[0]);
const stairs = input.slice(1).map(Number);

// DP 배열 생성
const dp = Array(n + 1).fill(0);

// 초기값 설정
if (n >= 1) dp[1] = stairs[0]; // 계단이 1개일 경우
if (n >= 2) dp[2] = stairs[0] + stairs[1]; // 계단이 2개일 경우

// DP 점화식
for (let i = 3; i <= n; i++) {
    // i번째 계단에 도달하는 경우:
    // 1. i-2번째 계단에서 2칸 뛰어서 오는 경우
    // 2. i-1번째 계단에서 1칸 올라오는 경우 (단, i-1은 i-3에서 와야 함)
    dp[i] = Math.max(
        dp[i-2] + stairs[i-1], // i-2에서 2칸 뛰어서 i로
        dp[i-3] + stairs[i-2] + stairs[i-1] // i-3에서 i-1로, i-1에서 i로
    );
}

// 결과 출력
console.log(dp[n]);
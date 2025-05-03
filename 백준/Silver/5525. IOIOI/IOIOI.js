const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const N = parseInt(input[0]);
const M = parseInt(input[1]);
const S = input[2];

const PN = 'IO'.repeat(N) + 'I';

let count = 0;
let i = 0;

while (i < M) {
  if (S.slice(i, i + PN.length) === PN) {
    count++;
    i += 2;
  } else {
    i++;
  }
}
console.log(count);
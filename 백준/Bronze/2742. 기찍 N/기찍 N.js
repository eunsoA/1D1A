const fs = require('fs');
const n = Number(fs.readFileSync('/dev/stdin').toString().trim());

let result = '';
for (let i = n; i >= 1; i--) {
  result += i + '\n';
}
console.log(result);

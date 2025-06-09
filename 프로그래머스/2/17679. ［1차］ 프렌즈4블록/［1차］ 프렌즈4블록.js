function check(m, n, grid) {
  let count = 0;
  const changed = Array.from({ length: m }, () => Array(n).fill(false));

  for (let i = 0; i < m - 1; i++) {
    for (let j = 0; j < n; j++) {
      if (grid[i][j] !== '*') {
        const block = grid[i][j];
        if (grid[i + 1][j] === block && grid[i][j + 1] === block && grid[i + 1][j + 1] === block) {
          if (!changed[i][j]) {
            changed[i][j] = true;
            count++;
          }
          if (!changed[i + 1][j]) {
            changed[i + 1][j] = true;
            count++;
          }
          if (!changed[i][j + 1]) {
            changed[i][j + 1] = true;
            count++;
          }
          if (!changed[i + 1][j + 1]) {
            changed[i + 1][j + 1] = true;
            count++;
          }
        }
      }
    }
  }

  // 체크된 블록 초기화
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (changed[i][j]) {
        grid[i][j] = '*';
      }
    }
  }

  // 블록 내리기
  for (let i = m - 1; i >= 0; i--) {
    for (let j = 0; j < n; j++) {
      if (grid[i][j] === '*') {
        for (let k = i - 1; k >= 0; k--) {
          if (grid[k][j] !== '*') {
            grid[i][j] = grid[k][j];
            grid[k][j] = '*';
            break;
          }
        }
      }
    }
  }
  return count;
}

function solution(m, n, board) {
  const grid = board.map((row) => row.split(''));
  const filled = Array.from({ length: m }, () => Array(n).fill(true));

  let result = 0;

  while (true) {
    const count = check(m, n, grid, filled);
    if (count === 0) break;
    result += count;
  }
  return result;
}

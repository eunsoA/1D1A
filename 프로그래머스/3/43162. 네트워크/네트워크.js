function solution(n, computers) {
  const nets = []; // Set들의 배열

  // node가 들어있는 Set의 인덱스 반환, 없으면 -1
  const findSetIndex = (node) => {
    for (let k = 0; k < nets.length; k++) {
      if (nets[k].has(node)) return k;
    }
    return -1;
  };

  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      if (computers[i][j] === 1) {
        const idxI = findSetIndex(i);
        const idxJ = findSetIndex(j);

        if (idxI === -1 && idxJ === -1) {
          // 둘 다 속한 set이 없으면 새로 생성
          nets.push(new Set([i, j]));
        } else if (idxI !== -1 && idxJ === -1) {
          // i가 있는 set에 j 추가
          nets[idxI].add(j);
        } else if (idxI === -1 && idxJ !== -1) {
          // j가 있는 set에 i 추가
          nets[idxJ].add(i);
        } else if (idxI !== idxJ) {
          // 서로 다른 set이면 병합 (작은 인덱스에 합치고 큰 인덱스 삭제)
          const a = Math.min(idxI, idxJ);
          const b = Math.max(idxI, idxJ);
          for (const v of nets[b]) nets[a].add(v);
          nets.splice(b, 1);
        }
        // idxI === idxJ이면 이미 같은 네트워크임
      }
      // computers[i][j] === 0일 때는 아무 행동 안 함 (0마다 새 Set 만들면 안 됨)
    }
  }

  // 아직 어떤 Set에도 없는(완전 고립된) 노드들을 추가
  for (let i = 0; i < n; i++) {
    if (findSetIndex(i) === -1) {
      nets.push(new Set([i]));
    }
  }

  return nets.length;
}

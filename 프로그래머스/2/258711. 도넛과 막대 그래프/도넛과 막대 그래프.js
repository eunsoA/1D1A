function solution(edges) {
  // 등장 노드 모으기
  const nodes = new Set();
  let maxNode = 0;
  for (const [u, v] of edges) {
    nodes.add(u); nodes.add(v);
    if (u > maxNode) maxNode = u;
    if (v > maxNode) maxNode = v;
  }

  // 차수 배열
  const inDe = Array(maxNode + 1).fill(0);
  const outDe = Array(maxNode + 1).fill(0);
  for (const [u, v] of edges) {
    inDe[v]++; outDe[u]++;
  }

  // 생성 정점
  let gen = -1;
  for (const i of nodes) {
    if (inDe[i] === 0 && outDe[i] >= 2) { gen = i; break; }
  }

  // 막대/8자 카운트 (등장한 노드만)
  let stick = 0, eight = 0;
  for (const i of nodes) {
    if (i === gen) continue;
    if (outDe[i] === 0) stick++;
    else if (inDe[i] >= 2 && outDe[i] >= 2) eight++;
  }

  const donut = outDe[gen] - stick - eight;
  return [gen, donut, stick, eight];
}

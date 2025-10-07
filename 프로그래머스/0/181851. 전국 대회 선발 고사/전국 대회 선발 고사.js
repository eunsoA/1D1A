function solution(rank, attendance) {
  const picked = rank
    .map((r,i)=> ({r,i}))
    .filter(({i})=> attendance[i])
    .sort((a,b)=> a.r - b.r)
    .slice(0,3)
    .map(o => o.i);
    
    return 10000*picked[0] + 100 * picked[1] + picked[2];
}

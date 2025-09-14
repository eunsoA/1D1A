function solution(arr) {
  // arr 의 length 가 거듭제곱인지 판단
  const length = arr.length;
  // 최소만큼 0 을 arr 에 추가한 후 반환
  const minLength = Math.pow(2, Math.ceil(Math.log2(length)));
  const diff = minLength - length;
  return [...arr, ...Array(diff).fill(0)];
}

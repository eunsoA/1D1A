function solution(arr) {
  // arr 의 length 가 거듭제곱인지 판단
  const length = arr.length;
  const isPowerOfTwo = (length) => {
    return (length & (length - 1)) === 0;
  };
  if (isPowerOfTwo(length)) {
    return arr;
  }
  const minLength = Math.pow(2, Math.ceil(Math.log2(length)));
  const diff = minLength - length;
  return [...arr, ...Array(diff).fill(0)];
}
function solution(n, arr1, arr2) {
    return arr1.map((num1, i)=>{
        const orResult = (num1|arr2[i]).toString(2).padStart(n, '0');
        return orResult.replace(/./g , ch => ch === '1' ? '#' : ' ');
    });
}
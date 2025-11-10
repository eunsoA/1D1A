function checkSosu(num) {
    if(num <= 1) return false;
    
    for(let i = 2; i <= Math.sqrt(num); i++) {
        if(num % i === 0) return false;
    }
    
    return true;
}

function getPermutations(arr, len){
    if(len === 1) return arr.map(v => [v]);
    const results = [];
    arr.forEach((fixed, index, origin) => {
        const rest = [...origin.slice(0, index), ...origin.slice(index + 1)];
        const perms = getPermutations(rest, len - 1);
        const attached = perms.map(v => [fixed, ...v]);
        results.push(...attached);
    });

    return results;
}

function solution(numbers) {
    const sosuSet = new Set();
    
    // 자르기
    const nums = numbers.split(''); // 1-7개의 문자열
    
    // 원소들 뽑아오기
    for(let len =1; len <= nums.length; len++){
        const perms = getPermutations(nums, len);
        perms.forEach((p) => {
            const num = Number(p.join(''));
            if(checkSosu(num)) sosuSet.add(num);
        })
    }
    
    return sosuSet.size;
}
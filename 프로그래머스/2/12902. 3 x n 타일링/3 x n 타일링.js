function solution(n) {
    const MOD = 1000000007;
    if (n % 2 === 1) return 0;
    
    const dp = Array(n+1).fill(0);
    dp[0] = 1;
    dp[2] = 3;
    
    for(let i = 4; i<=n; i += 2){
        let sum = 0;
        for(let j = 0; j<=i-4; j+=2){
            sum += dp[j];
        }
        
        dp[i] = (dp[i-2] * dp[2] + sum*2) % MOD;
    }
    
    return dp[n];
}